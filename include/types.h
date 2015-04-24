#ifndef mytypes
#define mytypes

#include <string>
#include <unordered_map>
#include <exception>
#include <limits>
#include <iostream>

namespace lzw{

// basic types
typedef std::uint16_t                                   lzw_code_t;
typedef std::unordered_map<std::string, lzw_code_t>     lzw_dict_t;

// enums used to specify alphabet
typedef enum {
      E_STANDARD_TXT = 0
    , E_GIF //       = 1
} alphabet_t;

// globals (externs)
extern alphabet_t g_alphabet_type;
extern lzw_dict_t g_dictionary;

// globals
static const lzw_code_t g_code_max = std::numeric_limits<lzw_code_t>::max();

// some basic functions declarations
void dict_reset();
void dict_print();
void dict_add();

} // namespace lzw



#endif // mytypes
