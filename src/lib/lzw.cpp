///
/// @file
/// @brief LZW file lib
///

#include "lib/lzw.h"
#include <vector>
#include <iostream>

std::vector<char> operator + (std::vector<char> vc, char c)
{
    vc.push_back(c);
    return vc;
}
namespace lzw
{
void compress(std::istream &is, std::ostream &os)
{
    lzw_dict_t dict;
    try{
        dict_reset(dict);
    }catch(std::out_of_range e){
        std::cout << "[compress(...)] err: " <<  e.what() << ", globals not set corectly" << std::endl;
        return;
    }

    std::vector<char> s;
    char c;

    while (is.get(c))
    {
        // dictionary's maximum size was reached
        if (dict.size() == g_code_max)
            dict_reset(dict);

        s.push_back(c);

        if (dict.count(s) == 0)
        {
            const lzw_code_t dict_size = dict.size();

            dict[s] = dict_size;
            s.pop_back();
            os.write(reinterpret_cast<const char *> (&dict.at(s)), sizeof (lzw_code_t));
            s = {c};
        }
    }

    if (!s.empty())
        os.write(reinterpret_cast<const char *> (&dict.at(s)), sizeof (lzw_code_t));
}

void decompress(std::istream &is, std::ostream &os)
{
    lzw_dec_dict_t dict;
    dict_reset(dict);

    std::vector<char> s;
    lzw_code_t k;
    int i =0;
    while (is.read(reinterpret_cast<char *> (&k), sizeof (lzw_code_t)))
    {
        // dictionary's maximum size was reached
//        std::cout << dict.size() <<" " << g_code_max <<"\n";
        if (dict.size() == g_code_max){
            dict_reset(dict);
            std::cout<< "reseting " <<i++<< "\n";
        }

        if (k > dict.size())
            throw std::runtime_error("invalid compressed code");

        if (k == dict.size()){
            dict.push_back(s + s.front());
        }
        else{
            if (!s.empty()){
                dict.push_back(s + dict.at(k).front());
            }
        }

        os.write(&dict.at(k).front(), dict.at(k).size());
        s = dict.at(k);
    }

    if (!is.eof() || is.gcount() != 0)
        throw std::runtime_error("corrupted compressed file");
}
} // namespace lzw
