#include "my_allocator.h"
#include <iostream>
#include <memory>
#include <fmt/core.h>

#define UNUSED(variable) (void)variable

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        int x = 635;
        int* ptr = &x;
        std::cout << ptr << std::endl;
        const auto ptr_bits = std::bit_cast<uintptr_t>(ptr);
        std::bitset<32> bits(ptr_bits);
        // int a = 1;
        // std::cout << "Hello world" << std::endl;
        // fmt::print("Hello from fmt {}", a);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
