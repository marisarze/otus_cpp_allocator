#include "include/pool_allocator.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>    
#include <algorithm>
#include <cstdint>

template <class T, std::size_t alignment = 64>
PoolAllocator<T, alignment>::PoolAllocator(size_t in_reserve_elements_number)
: reserve_width{in_reserve_width}(
    entry_size_bytes = (sizeof(Node)+alignment-1) & -alignment;
    segment_width_bytes = entry_size_bytes * (in_reserve_elements_number + 1);
)

PoolAllocator::~PoolAllocator() {
    std::free(start_ptr);
}

template <class T, std::size_t alignment = 64>
void *PoolAllocator<T, alignment>::allocate(size_t in_num_elements) {
    auto free_position = free_list.pop();
    if (free_position==nullptr){
        expand(num_elements);
        free_position = free_list.pop(); 
    }
    return (void*) free_position;
}

template <class T, std::size_t alignment = 64>
void PoolAllocator<T, alignment>::deallocate(void* ptr) {
    free_list.push((Node*) ptr);


template <class T, std::size_t alignment = 64>
void* PoolAllocator<T, alignment>::expand() {
    void* segment_start_ptr = std::malloc((reserve_width+1) * entry_size);
    if (start_ptr==nullptr)
        start_ptr = segment_start_ptr;
    else (
        Node* next_segment_ptr = (uintptr_t)last_segment_ptr+(reserve_element_number+1)*entry_size_bytes;
        next_segment_ptr->next = 
    )
    for (int i = 0; i < reserve_elements_number; ++i) {
        std::size_t address = (uintptr_t) segment_start_ptr + i * entry_size_bytes;
        m_freeList.push((Node *) address);
    }
}