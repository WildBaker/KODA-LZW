#include "types.h"

namespace lzw
{
void dict_reset(){
    switch(g_alphabet_type){
        case E_STANDARD_TXT:
            static const long int minc = std::numeric_limits<char>::min();
            static const long int maxc = std::numeric_limits<char>::max();

            for (long int c = minc; c <= maxc; c++){
                const lzw_code_t dict_size = g_dictionary.size();
                g_dictionary[{static_cast<char> (c)}] = dict_size;
            }
            break;
        case E_GIF:
            // TO_DO
            throw std::out_of_range("to be done");
            break;
        default:
            throw std::out_of_range("g_alphabet_type not set correctly!");
            break;

    }
}

void dict_print(){
    std::cout << "dict size : " << g_dictionary.size() << std::endl;
    std::cout << "dict listed: " << std::endl;
    int i =1;
    for( auto it = g_dictionary.begin(); it != g_dictionary.end(); ++it ){

        std::cout << " " << it->first << ":" << it->second;
        if(i++%6 == 0)
            std::cout << std::endl;
        else
            std::cout << "\t|\t";
    }
}

void dict_add(){
std::cout<<"add\n";
}
} // namespace lzw
