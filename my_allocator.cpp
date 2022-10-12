/**
 * @file editor.cpp
 * @author marisarze (you@domain.com)
 * @brief 
 * @version MY_PROJECT_VERSION
 * @date BUILD_DATE
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#define UNUSED(variable) (void)variable

#include "my_allocator.h"
#include <iostream>
#include <memory>
#include <vector>
#include <cstddef>



template <typename T, std::size_t NUM_ELEMENTS>
MyAllocator<T, NUM_ELEMENTS>::MyAllocator() {
}

template <typename T, std::size_t NUM_ELEMENTS>
template <typename U, std::size_t OTHER_NUM_ELEMENTS>
MyAllocator<T, NUM_ELEMENTS>::MyAllocator(const MyAllocator<U, OTHER_NUM_ELEMENTS>& ) {
	// should we make a copy of the rhs.m_buffer ?
	// No, we should not!
}

template <typename T, std::size_t NUM_ELEMENTS>
T* MyAllocator<T, NUM_ELEMENTS>::allocate (std::size_t n) {
	auto p = std::malloc(n * sizeof(T));
	if (!p)
		throw std::bad_alloc();
	return reinterpret_cast<T *>(p);
}

template <typename T, std::size_t NUM_ELEMENTS>
void MyAllocator<T, NUM_ELEMENTS>::deallocate (T* p, std::size_t ) {
	std::free(p);
}

template <class T, class U, std::size_t NUM_ELEMENTS, std::size_t OTHER_NUM_ELEMENTS>
constexpr bool operator== (const MyAllocator<T, NUM_ELEMENTS>&, const MyAllocator<U, OTHER_NUM_ELEMENTS>&) noexcept {
	return false;
}

template <class T, class U, std::size_t NUM_ELEMENTS, std::size_t OTHER_NUM_ELEMENTS>
constexpr bool operator!= (const MyAllocator<T, NUM_ELEMENTS>&, const MyAllocator<U, OTHER_NUM_ELEMENTS>&) noexcept {
	return false;
}