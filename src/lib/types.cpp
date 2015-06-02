///
/// @file
/// @brief types file
///
#include "lib/types.h"
#include <iomanip>

namespace lzw
{


std::vector<char> get_alphabet(){
    std::vector<char> ret;
    switch(g_alphabet_type){
    case E_STANDARD_TXT:
    {
        const long int minc = std::numeric_limits<char>::min();
        const long int maxc = std::numeric_limits<char>::max();

        for (long int c = minc; c <= maxc; c++)
            ret.push_back(static_cast<char> (c));
        break;
    }
    case E_GIF:
        // TO_DO
        throw std::out_of_range("to be done");
        break;
    default:
        throw std::out_of_range("g_alphabet_type not set correctly!");
        break;
    }
    return ret;
}
void print_alphabet(std::vector<char> &a){
    std::cout<<"\n==========================================================\n";
    int ii = 1;
    for(auto i = a.begin(); i<a.end(); i++){
        std::cout << std::left << std::setw(12) << std::setfill(' ')<< (*i);
        if(ii++%12 == 0)
            std::cout << std::endl;
    }

    std::cout<<"\n=========================================================="<<std::endl;
}


void dict_reset(lzw_dict_t &a_dictionary){
    std::vector<char> alph;
    try{
        alph = get_alphabet();
    }catch(std::out_of_range e){
        std::cerr << "[dict_reset]: err: " << e.what()<<std::endl;
        return;
    }
//    print_alphabet(alph);

    a_dictionary.clear();
    for(auto it=alph.begin(); it != alph.end(); it++){
        const lzw_code_t dict_size = a_dictionary.size();
        std::vector<char> temp;
        temp.push_back(*it);
        a_dictionary[temp] = dict_size;
    }
}
void dict_reset(lzw_dec_dict_t &a_dictionary){
    std::vector<char> alph;
    try{
         alph = get_alphabet();
    }catch(std::out_of_range e){
        std::cerr << "[dict_reset]: err: " << e.what()<<std::endl;
        return;
    }
//    print_alphabet(alph);

    a_dictionary.clear();
    for(auto it=alph.begin(); it != alph.end(); it++){
        std::vector<char> temp;
        temp.push_back(*it);
        a_dictionary.push_back(temp);
//        const lzw_code_t dict_size = g_dictionary.size();
//        g_dictionary[(*it)] = dict_size;
    }
}

void dict_print(lzw_dict_t &a_dictionary){
    std::cout << "\n===\nprinting compression dictionary: \n";
    std::cout << "dict size : " << a_dictionary.size() << std::endl;
    std::cout << "dict listed: " << std::endl;
    int i =1;
    for( auto it = a_dictionary.begin(); it != a_dictionary.end(); ++it ){
        std::cout << std::left << std::setw(13) << std::setfill(' ') << it->first.data();
        if(i++%12 == 0)
            std::cout << std::endl;
    }
}

void dict_print(lzw_dec_dict_t &a_dictionary){
    std::cout << "\n===\nprinting decompression dictionary: \n";
    std::cout << "dict size : " << a_dictionary.size() << "\n";
    std::cout << "dict listed: " << std::endl;
    int i =1;
    for( auto it = a_dictionary.begin(); it != a_dictionary.end(); ++it ){

        std::cout << std::left << std::setw(12) << std::setfill(' ')<< it->data();
        if(i++%12 == 0)
            std::cout << std::endl;
    }
}
} // namespace lzw
