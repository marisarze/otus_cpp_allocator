#include "allocator.h"
#include "stack_linked_list.h"

class PoolAllocator : public Allocator {
private:
    struct  FreeHeader{
    };
    using Node = StackLinkedList<FreeHeader>::Node;
    StackLinkedList<FreeHeader> free_list;

    void* start_ptr = nullptr;
    std::size_t chunk_size;
public:
    PoolAllocator(const std::size_t in_total_size, const std::size_t in_chunk_size);

    virtual ~PoolAllocator();

    virtual void* allocate(const std::size_t size, const std::size_t alignment = 0) override;

    virtual void free(void* ptr) override;

    virtual void init() override;

    virtual void reset();
private:
    PoolAllocator(PoolAllocator &poolAllocator);

};