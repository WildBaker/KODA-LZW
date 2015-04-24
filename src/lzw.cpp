///
/// @file
/// @brief LZW file lib
///

#include "lzw.h"
#include <vector>

namespace lzw
{
void compress(std::istream &is, std::ostream &os)
{
    try{
        dict_reset();
    }catch(std::out_of_range e){
        std::cout << "[compress(...)] err: " <<  e.what() << ", globals not set corectly" << std::endl;
        return;
    }

    std::string s;
    char c;

    while (is.get(c))
    {
        // dictionary's maximum size was reached
        if (g_dictionary.size() == g_code_max)
            dict_reset();

        s.push_back(c);

        if (g_dictionary.count(s) == 0)
        {
            const lzw_code_t dict_size = g_dictionary.size();

            g_dictionary[s] = dict_size;
            s.pop_back();
            os.write(reinterpret_cast<const char *> (&g_dictionary.at(s)), sizeof (lzw_code_t));
            s = {c};
        }
    }

    if (!s.empty())
        os.write(reinterpret_cast<const char *> (&g_dictionary.at(s)), sizeof (lzw_code_t));
}

void decompress(std::istream &is, std::ostream &os)
{
    std::vector<std::string> dec_dict;

    const auto dict_dec_reset = [&dec_dict] {
        dict_reset();
        dec_dict.clear();
        for(auto it = g_dictionary.begin(); it != g_dictionary.end(); it++){
            dec_dict.push_back(it->first);
        }
    };
    dict_dec_reset();


    std::string s;
    lzw_code_t k;

    while (is.read(reinterpret_cast<char *> (&k), sizeof (lzw_code_t)))
    {
        // dictionary's maximum size was reached
        if (g_dictionary.size() == g_code_max)
            dict_dec_reset();

        if (k > dec_dict.size())
            throw std::runtime_error("invalid compressed code");

        if (k == dec_dict.size())
            dec_dict.push_back(s + s.front());
        else
        if (!s.empty())
            dec_dict.push_back(s + dec_dict.at(k).front());

        os.write(&dec_dict.at(k).front(), dec_dict.at(k).size());
        s = dec_dict.at(k);
    }

    if (!is.eof() || is.gcount() != 0)
        throw std::runtime_error("corrupted compressed file");
}
} // namespace lzw
