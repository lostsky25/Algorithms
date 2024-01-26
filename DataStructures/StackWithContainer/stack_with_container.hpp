#pragma once

#include <list>
#include <memory>

template <class T, class Container = std::list<T>>
class Stack {
public:
    using value_type = T;

	// non-const using defines
	using reference = value_type&;

	// const using defines
	using const_reference = const value_type&;

public:
    Stack () {}

    size_t size() const noexcept {
        return c.size();
    }

    bool empty() const noexcept {
        return c.empty();
    }

    void push(const T& val) {
        c.push_back(val);
    }

    void pop() {
        c.pop_back();
    }
    
    reference top() {
        return c.back();
    }

private:
    Container c;
};