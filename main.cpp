#include "pool_allocator.h"
//#include <iostream>
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


/**
 * @brief Utility function for printing messages using <fmt> library plus new line character.
 * Usage: println("Some sentence for formatting {}", "XXX") results to "Some sentence for formatting XXX"
 *  
 * @tparam Args types of parameters for formatting target message
 * @param format target message for printing
 * @param args formatting variables
 */
template <typename... Args>
void println(std::string format, const Args&... args) {
  fmt::print(format, args...);
  std::putc('\n', stdout);
}



int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        // using r = PoolAllocator<int, 10, 16>;
        // r::print();
        //std::map<std::pair<int, int>, PoolAllocator<std::pair<int, int>>> mymap;
        std::vector<int, PoolAllocator<int, 10, 32>> myvec;
        for (int i=0;i<10;i++){
            myvec.push_back(i);
        }
        // std::fill(myvec.begin(), myvec.end(), -4);
        // for (auto elem: myvec){
        //     fmt::print("{}", elem);
        // }

        
    }
    catch(const std::exception &e)
    {
        //std::cerr << e.what() << std::endl;
    }

    return 0;
}
