#ifndef DEQUE_H
#define DEQUE_H

#include "Student.h"
#include "Iterator.h"
#include <stdexcept>
#include <algorithm>

class Deque23 {

    friend class Iterator;

public:
    Deque23();
    ~Deque23();
    Deque23(const Deque23& other);
    Deque23(Deque23&& other) noexcept;
    Deque23& operator=(Deque23 other);

    void swap(Deque23& other) noexcept;

    bool empty() const;
    int size() const;

    void push_back(const Student& s);
    void push_front(const Student& s);
    void pop_back();
    void pop_front();

    Student& front_();
    Student& back_();
    Student& at(int index);
    Student& operator[](int index);

    void clear();

    // Iterators for range-based for
    Iterator begin();
    Iterator end();

private:
    Student* data;    // Array for deque elements
    int capacity;     // Buffer capacity
    int real_size;    // Number of elements in deque
    int front;        // Index of first element

    // Expand the buffer if elements are larger than the current capacity
    void reallocate();
};

#endif // DEQUE_H