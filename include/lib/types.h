#ifndef mytypes
#define mytypes

#include <string>
#include <unordered_map>
#include <exception>
#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>

namespace lzw{
// hashing function
struct hash_vect_char {
    std::size_t operator () (const std::vector<char> &vc) const
    {
        return std::hash<std::string>()(std::string(vc.cbegin(), vc.cend()));
    }
};

// basic types
typedef std::uint8_t                                                        lzw_code_t;
typedef std::unordered_map<std::vector<char>, lzw_code_t,hash_vect_char>    lzw_dict_t;
typedef std::vector<std::vector<char> >                                     lzw_dec_dict_t;

// enums used to specify alphabet
typedef enum {
      E_STANDARD_TXT = 0
    , E_GIF //       = 1
} alphabet_t;

// globals
static lzw_code_t g_code_max = std::numeric_limits<lzw_code_t>::max();
void SetCodeMax(lzw_code_t newMax);

extern alphabet_t g_alphabet_type;

// some basic functions declarations
std::vector<char> get_alphabet();
void print_alphabet(std::vector<char> &a);

void dict_reset(lzw_dict_t &a_dictionary);
void dict_print(lzw_dict_t &a_dictionary);

void dict_reset(lzw_dec_dict_t &a_dictionary);
void dict_print(lzw_dec_dict_t &a_dictionary);
} // namespace lzw



#endif // mytypes
