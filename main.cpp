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
        std::cout << "Hello world" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
