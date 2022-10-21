#include "allocator.h"
#include "stack_linked_list.h"
#include <cstdint>

template <class T, std::size_t alignment = 64>
class PoolAllocator {
private:
    using Node = StackLinkedList<T>::Node;
    StackLinkedList<T> free_list;

    void* start_ptr = nullptr;
    std::size_t reserve_elements_number, segment_width_bytes, entry_size_bytes;
public:
    PoolAllocator(const std::size_t in_reserve_elements_number);

    ~PoolAllocator();

    void* allocate(const std::size_t num_elements);

    void deallocate(void* ptr);

    void expand();
private:
    PoolAllocator(PoolAllocator &poolAllocator);

};