

#include <cstddef>

class Allocator {
protected:
    std::size_t total_size;
    std::size_t used = 0;
public:
    
    Allocator(const std::size_t in_total_size) : total_size { in_total_size } { }
    
    virtual ~Allocator() { total_size = 0; }
    virtual void* allocate(const std::size_t size, const std::size_t alignment = 0) = 0;
    virtual void free(void* ptr) = 0;
    virtual void init() = 0;
};