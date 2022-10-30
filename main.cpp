#include "pool_allocator.h"
#include <iostream>
#include <memory>
//#include <fmt/core.h>
#include <cstdint>
#include <bitset>
#include <ctime>
#include <chrono>
#include <memory.h>
#include <map>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <cmath>
#define UNUSED(variable) (void)variable


// /**
//  * @brief Utility function for printing messages using <fmt> library plus new line character.
//  * Usage: println("Some sentence for formatting {}", "XXX") results to "Some sentence for formatting XXX"
//  *  
//  * @tparam Args types of parameters for formatting target message
//  * @param format target message for printing
//  * @param args formatting variables
//  */
// template <typename... Args>
// void println(std::string format, const Args&... args) {
//   fmt::print(format, args...);
//   std::putc('\n', stdout);
// }

int fact(int n){
    return std::tgamma(n + 1);  
}  


int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        // using r = PoolAllocator<int, 10, 16>;
        // r::print();
        // std::vector<int, PoolAllocator<int, 10, 64>> myvec;
        std::map<int, int, std::less<int>, PoolAllocator<std::pair<int, int>, 10, 64>> mymap;
        int n = 10;
        for (int i=0;i<n;i++){
            mymap[i] = fact(i);
        }
        for (auto it = mymap.begin();it!=mymap.end();it++){
            std::cout << it->first << " " << it->second << std::endl;
        }

        
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
