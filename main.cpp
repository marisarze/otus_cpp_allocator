#include "pool_allocator.h"
#include <iostream>
#include <memory>
#include <fmt/core.h>
#include <cstdint>
#include <bitset>
#include <ctime>
#include <chrono>
#include <memory.h>
#include <map>
#include <vector>
#define UNUSED(variable) (void)variable


int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        //std::map<std::pair<int, int>, PoolAllocator<std::pair<int, int>>> mymap;
        std::vector<int, PoolAllocator<int, 10>> myvec;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
