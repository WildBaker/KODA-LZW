///
/// @file
/// @brief LZW test
///
#include <iostream>
#include "lib/types.h"

namespace lzw{
alphabet_t g_alphabet_type = E_STANDARD_TXT;
} // namespace lzw


using namespace lzw;
int main()
{

    lzw_dec_dict_t dec_dict;
    dict_reset(dec_dict);
    dict_print(dec_dict);

    lzw_dict_t dict;
    dict_reset(dict);
    dict_print(dict);

    return 0;
}

