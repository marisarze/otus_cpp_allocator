#include "pool_allocator.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>    
#include <algorithm>


PoolAllocator::PoolAllocator(const std::size_t in_total_size, const std::size_t in_chunk_size)
: Allocator(in_total_size) {
    assert(in_chunk_size >= 8 && "Chunk size must be greater or equal to 8");
    assert(in_total_size % in_chunk_size == 0 && "Total size must be a multiple of chunk size");
    this->chunk_size = in_chunk_size;
}

void PoolAllocator::init() {
    start_ptr = std::malloc(total_size);
    this->reset();
}

PoolAllocator::~PoolAllocator() {
    std::free(start_ptr);
}

void *PoolAllocator::allocate(size_t num_elements) {
    auto free_position = free_list.pop();
    if (free_position==nullptr){

    }
        expand(num_elements);
        free_position = free_list.pop(); 
    return free_position;
    assert(in_allocation_size == this->chunk_size && "Allocation size must be equal to chunk size");

    Node* free_position = free_list.pop();

    assert(freePosition != nullptr && "The pool allocator is full");

    used += chunk_size;
    return (void*) free_position;
}

void PoolAllocator::free(void* ptr) {
    used -= chunk_size;

    free_list.push((Node*) ptr);



void PoolAllocator::Reset() {
    m_used = 0;
    m_peak = 0;
    // Create a linked-list with all free positions
    const int nChunks = m_totalSize / element_ize;
    for (int i = 0; i < nChunks; ++i) {
        std::size_t address = (std::size_t) m_start_ptr + i * m_chunkSize;
        m_freeList.push((Node *) address);
    }
}