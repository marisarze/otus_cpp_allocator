#include "pool_allocator.h"
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <iostream>

#define UNUSED(variable) (void)variable

template <typename T, std::size_t reserve_size, std::size_t alignment>
void PoolAllocator<T, reserve_size, alignment>::print()
{
    std::cout << "Hello from allocator"<< std::endl;
}

template <typename T, std::size_t reserve_size, std::size_t alignment>
PoolAllocator<T, reserve_size, alignment>::PoolAllocator()
{
    entry_size = (sizeof(Node)+alignment-1) & -alignment;
    segment_width = entry_size * (reserve_size+1);
}


template <typename T, std::size_t reserve_size, std::size_t alignment>
PoolAllocator<T, reserve_size, alignment>::~PoolAllocator() {
    while(true){
        auto ptr = segments.pop();
        if(ptr)
            std::free(ptr);
        else
            return;
    }    
}


template <typename T, std::size_t reserve_size, std::size_t alignment>
void* PoolAllocator<T, reserve_size, alignment>::allocate(size_type num_elements) {
    auto free_position = free_list.pop();
    if (free_position==nullptr){
        expand();
        free_position = free_list.pop(); 
    }
    return (void*)free_position;
}


template <typename T, std::size_t reserve_size, std::size_t alignment>
void PoolAllocator<T, reserve_size, alignment>::deallocate(T* ptr, size_type n) {

    free_list.push((Node*) ptr);
}


template <typename T, std::size_t reserve_size, std::size_t alignment>
void PoolAllocator<T, reserve_size, alignment>::expand() {
    void* new_segment_ptr = std::malloc(segment_width);
    segments.push((Node*) new_segment_ptr);
    for (int i = 1; i <= reserve_size; ++i) {
        std::size_t address = (std::byte*)new_segment_ptr + i * entry_size;
        free_list.push((Node*) address);
    }
}