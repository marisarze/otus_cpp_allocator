#pragma once

#include <cstddef>

template <typename T, std::size_t NUM_ELEMENTS>
struct MyAllocator {
	using value_type = T;

	using pointer = T *;
	using const_pointer = const T *;
	using reference = T &;
	using const_reference = const T &;

	MyAllocator();

	template <typename U, std::size_t OTHER_NUM_ELEMENTS>
	MyAllocator(const MyAllocator<U, OTHER_NUM_ELEMENTS>&);

	T* allocate (std::size_t n);
	
	void deallocate (T* p, std::size_t n);
};