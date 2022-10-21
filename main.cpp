#include "my_allocator.h"
#include <iostream>
#include <memory>
#include <fmt/core.h>
#include <cstdint>
#include <bitset>
#include <ctime>
#include <chrono>

#define UNUSED(variable) (void)variable

uintptr_t bitwise(uintptr_t input, int alignment){
    return (input + alignment -1) & -alignment;
}

uintptr_t through_remainder(uintptr_t input, int alignment){
    uintptr_t temp = input % alignment;
    if (temp) return input - temp + 32; 
    return input;
}


int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        int x = 635;
        int* ptr = &x;
        std::cout << ptr << std::endl;
        const auto ptr_int = reinterpret_cast<uintptr_t>(ptr);
        uintptr_t bitwise_result, through_remainder_result;
        auto t0 = std::chrono::high_resolution_clock::now();
        for (int i=0;i<10000;i++){
            bitwise_result = bitwise(ptr_int, 32);
        }
        auto dt = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - t0);
        std::cout << "Bitwise time: " << dt.count() << std::endl;

        t0 = std::chrono::high_resolution_clock::now();
        for (int i=0;i<10000;i++){
            through_remainder_result = through_remainder(ptr_int, 32);
        }
        dt = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - t0);
        std::cout << "Through remainder time: " << dt.count() << std::endl;
        std::cout << "Through remainder result: " << through_remainder_result << std::endl;
        std::cout << "Bitwise result: " << bitwise_result << std::endl;
        const auto remainder = ptr_int % 32;
        const auto expected = ptr_int - remainder + 32;
        std::bitset<32> ptr_bits(ptr_int);
        std::bitset<32> align_bits(32);
        std::bitset<32> negate_align_bits(-32);
        
        std::cout << "Remainder of dividing the address by 32: " << remainder << std::endl;
        std::cout << "Expected adress after alignment: " << expected << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Initial ptr_bits:  " << ptr_bits << std::endl;
        std::cout << "Align bits:        " << align_bits << std::endl;
        std::cout << "Negate align bits: " << negate_align_bits << std::endl;
        std::cout << "---------------------------------" << std::endl;
        const auto extended = ptr_int + 32 - 1;
        const auto and_result = extended & -32;
        std::bitset<32> and_result_bit(and_result);
        std::bitset<32> extended_bits(extended);

        std::cout << "Extended bits:     " << extended_bits << std::endl;
        std::cout << "Negate align bits: " << negate_align_bits << std::endl;
        std::cout << "Bit and operation  " << and_result_bit << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Result:   " << and_result << std::endl;
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "---------------------------------" << std::endl;

        int a = 567;
        int* ptr2 = &a;
        std::cout << "some pointer adress: " << (uintptr_t)ptr2 << std::endl;


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
