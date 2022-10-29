#include "linked_list.h"
#include <cstdint>
#include <type_traits>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <iostream>



template <typename T, std::size_t reserve_size, std::size_t alignment>
class PoolAllocator {
private:
    using Node = typename StackLinkedList<T>::Node;
    StackLinkedList<T> free_list, segments;
    std::size_t segment_width, entry_size;
public:
    using value_type                                = T;
    using size_type                                 = std::size_t;
    using pointer                                   = T*;
    using const_pointer                             = const T*;
    using reference                                 = T&;
    using const_reference                           = const T&;
    using difference_type                           = std::ptrdiff_t;
    using propagate_on_container_move_assignment    = std::ptrdiff_t;
    template <typename U>
    struct rebind
    {
        using other = PoolAllocator<U, reserve_size, alignment>;
    };
    using is_always_equal                           = std::true_type;
    
    static void print();
    PoolAllocator();

    ~PoolAllocator();

    void* allocate(size_type num_elements);

    void deallocate(T* ptr, size_type n);

    void expand();
};


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
    UNUSED(n);
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