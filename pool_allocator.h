#include "linked_list.h"
#include <cstdint>
#include <type_traits>
#include <cstddef>

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