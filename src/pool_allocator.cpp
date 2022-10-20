#include "include/pool_allocator.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>    
#include <algorithm>
#include <cstdint>

template <class T, typename alignment= std::uint32_t>
PoolAllocator<T, alignment>::PoolAllocator(size_t in_reserve_width)
: reserve_width{in_reserve_width}(
    alignment temp = 0;
    entry_size_bytes = = (sizeof(Node)+size(alignment)-1) & ~alignment
)

PoolAllocator::~PoolAllocator() {
    std::free(start_ptr);
}

template <class T, typename alignment= std::uint32_t>
void *PoolAllocator<T, alignment>::allocate(size_t in_num_elements) {
    auto free_position = free_list.pop();
    if (free_position==nullptr){
        expand(num_elements);
        free_position = free_list.pop(); 
    }
    return (void*) free_position;
}

template <class T, typename alignment= std::uint32_t>
void PoolAllocator<T, alignment>::deallocate(void* ptr) {
    free_list.push((Node*) ptr);


template <class T, typename alignment= std::uint32_t>
void PoolAllocator<T, alignment>::expand() {
    void* segment_start_ptr = std::malloc((reserve_width+1) * entry_size);
    if (start_ptr==nullptr)
        start_ptr = segment_start_ptr;
    for (int i = 0; i < num_elements; ++i) {
        std::size_t address = (std::size_t) start_ptr + i * entry_size;
        m_freeList.push((Node *) address);
    }
}