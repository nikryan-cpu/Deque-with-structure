#include "Deque.h"

Deque23::Deque23() : capacity(8), real_size(0), front(0) {
    data = new Student[capacity];
}

Deque23::~Deque23() {
    delete[] data;
}

Deque23::Deque23(const Deque23& other)
    : capacity(other.capacity), real_size(other.real_size), front(other.front) {
    data = new Student[capacity];
    for (int i = 0; i < real_size; i++) {
        data[(front + i) % capacity] = other.data[(other.front + i) % capacity];
    }
}

Deque23::Deque23(Deque23&& other) noexcept
    : data(other.data), capacity(other.capacity), real_size(other.real_size), front(other.front) {
    other.data = nullptr;
    other.capacity = 0;
    other.real_size = 0;
    other.front = 0;
}

Deque23& Deque23::operator=(Deque23 other) {
    swap(other);
    return *this;
}

void Deque23::swap(Deque23& other) noexcept {
    std::swap(data, other.data);
    std::swap(capacity, other.capacity);
    std::swap(real_size, other.real_size);
    std::swap(front, other.front);
}

bool Deque23::empty() const {
    return real_size == 0;
}

int Deque23::size() const {
    return real_size;
}

void Deque23::reallocate() {
    int newCapacity = capacity * 2;
    Student* newData = new Student[newCapacity];
    for (int i = 0; i < real_size; i++) {
        newData[i] = data[(front + i) % capacity];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
    front = 0;
}

void Deque23::push_back(const Student& s) {
    if (real_size == capacity)
        reallocate();
    int index = (front + real_size) % capacity;
    data[index] = s;
    ++real_size;
}

void Deque23::push_front(const Student& s) {
    if (real_size == capacity)
        reallocate();
    front = (front - 1 + capacity) % capacity;
    data[front] = s;
    ++real_size;
}

void Deque23::pop_back() {
    if (empty())
        throw std::out_of_range("pop_back on empty deque");
    --real_size;
}

void Deque23::pop_front() {
    if (empty())
        throw std::out_of_range("pop_front on empty deque");
    front = (front + 1) % capacity;
    --real_size;
}

Student& Deque23::front_() {
    if (empty())
        throw std::out_of_range("front on empty deque");
    return data[front];
}

Student& Deque23::back_() {
    if (empty())
        throw std::out_of_range("back on empty deque");
    return data[(front + real_size - 1) % capacity];
}

Student& Deque23::at(int index) {
    if (index < 0 || index >= real_size)
        throw std::out_of_range("index out of range");
    return data[(front + index) % capacity];
}

Student& Deque23::operator[](int index) {
    return data[(front + index) % capacity];
}

void Deque23::clear() {
    real_size = 0;
    front = 0;
}

Iterator Deque23::begin() {
    return Iterator(this, 0);
}

Iterator Deque23::end() {
    return Iterator(this, real_size);
}