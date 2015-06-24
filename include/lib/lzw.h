#ifndef lzw_lib
#define lzw_lib

#include "types.h"
#include <stdexcept>
namespace lzw
{
void compress(std::istream &is, std::ostream &os);
void decompress(std::istream &is, std::ostream &os);

} // namespace lzw
#endif // lzw_lib
