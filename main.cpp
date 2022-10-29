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
#include <cstddef>
#include <algorithm>
#define UNUSED(variable) (void)variable


int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        // using r = PoolAllocator<int, 10, 16>;
        // r::print();
        //std::map<std::pair<int, int>, PoolAllocator<std::pair<int, int>>> mymap;
        std::vector<int, PoolAllocator<int, 10, 64>> myvec;
        std::fill(myvec.begin(), myvec.end(), -4);
        for (auto elem: myvec){
            fmt::print("{}", elem);
        }

        
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
