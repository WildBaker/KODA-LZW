///
/// @file
/// @brief LZW file decompression programm
///
#include "lzw.h"
#include <fstream>

namespace lzw{
alphabet_t g_alphabet_type = E_STANDARD_TXT;
} // namespace lzw

int main(int argc, char **argv)
{
    if(argc != 3){
        std::cout << "Wrong no of args...\n";
        return 1;
    }

    std::ifstream in_f(argv[1], std::ios_base::binary);
    std::ofstream out_f(argv[2], std::ios_base::binary);
    if (!in_f.is_open() || !out_f.is_open())
    {
        std::cout << "Cannot open given files!\n";
        return EXIT_FAILURE;
    }
    std::cout << "decompressing file...\n";
    lzw::decompress(in_f, out_f);
    std::cout << "done\n";
    return 0;
}
