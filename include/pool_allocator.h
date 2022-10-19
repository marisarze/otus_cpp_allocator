#include "allocator.h"
#include "stack_linked_list.h"

template <class T, typename alignment>
class PoolAllocator {
private:
    using Node = StackLinkedList<T>::Node;
    StackLinkedList<T> free_list;

    void* start_ptr = nullptr;
    std::size_t entry_size = (sizeof(Node)+size(alignment)-1) & ~sizeof(alignment);
public:
    PoolAllocator(const std::size_t in_chunk_size);

    virtual ~PoolAllocator();

    virtual void* allocate(const std::size_t size, const std::size_t alignment = 0) override;

    virtual void free(void* ptr) override;

    virtual void init() override;

    virtual void reset();
private:
    PoolAllocator(PoolAllocator &poolAllocator);

};