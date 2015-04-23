#include <iostream>
#include "types.h"

//namespace lzw{
lzw::alphabet_t lzw::g_alphabet_type = E_STANDARD_TXT;
lzw::lzw_dict_t lzw::g_dictionary;
//} // namespace lzw


using namespace lzw;
int main()
{
    dict_reset();
    dict_print();

//    lzw::dict_print();
//    lzw::dict_reset();
//    lzw::dict_print();

    std::cout << "Hello World!" << std::endl;
    return 0;
}

