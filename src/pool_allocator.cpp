#include "pool_allocator.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>    
#include <algorithm>


PoolAllocator::PoolAllocator(in_chunk_size)
: {}

PoolAllocator::~PoolAllocator() {
    std::free(start_ptr);
}


void *PoolAllocator::allocate(size_t num_elements) {
    auto free_position = free_list.pop();
    if (free_position==nullptr){
        expand(num_elements);
        free_position = free_list.pop(); 
    }
    return (void*) free_position;
}


void PoolAllocator::deallocate(void* ptr) {
    free_list.push((Node*) ptr);


void PoolAllocator::expand() {
    start_ptr = std::malloc(total_size);
    for (int i = 0; i < num_elements; ++i) {
        std::size_t address = (std::size_t) start_ptr + i * entry_size;
        m_freeList.push((Node *) address);
    }
}