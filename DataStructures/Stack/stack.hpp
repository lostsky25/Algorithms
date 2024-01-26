#pragma once

#include <memory>

template <class T, class Alloc = std::allocator<T>>
class Stack {
public:
    using value_type = T;
    using traits = std::allocator_traits<Alloc>;

	// non-const using defines
	using pointer = value_type*;
	using reference = value_type&;

	// const using defines
	using const_pointer = const value_type*;
	using const_reference = const value_type&;

public:
    Stack () : data(nullptr), sz(0), cap(0) {}

    size_t size() const noexcept {
        return sz;
    }

    bool empty() const noexcept {
        return sz == 0;
    }

    void push(const T& val) {
        if (data == nullptr) {
            reserve(1);
        }

        if (cap == sz && sz > 0) {
            reserve(cap * 2);
        }

        traits::construct(alloc, data + sz, T(val));
        ++sz;
    }

    void pop() {
        (data + sz - 1)->~T();
        --sz;
    }
    
    reference top() {
        return data[sz - 1];
    }

    void swap(Stack<T>& right) {
        pointer tmp = right.data;
        size_t tmp_sz = right.sz;
        size_t tmp_cap = right.cap;

        right.data = data;
        right.cap = cap;
        right.sz = sz;

        data = tmp;
        cap = tmp_cap;
        sz = tmp_sz;
    }

private:
    void reserve(size_t n) {
        if (n <= cap) {
            return;
        }

        pointer newData = traits::allocate(alloc, n);

        for (size_t i = 0; i < sz; ++i) {
            traits::construct(alloc, newData + i, data[i]);
        }

        for (size_t i = 0; i < sz; ++i) {
            (data + i)->~T();
        }

        traits::deallocate(alloc, data, n);
        data = newData;
        cap = n;
    }

    pointer data;
    size_t cap;
    size_t sz;
    Alloc alloc;
};