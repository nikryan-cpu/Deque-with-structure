#include "Iterator.h"
#include "Deque.h" // Для доступа к закрытым членам Deque23

Iterator::Iterator(Deque23* d, int p) : deque(d), pos(p) {}

Iterator::Iterator() : deque(nullptr), pos(0) {}

Student& Iterator::operator*() const {
    if (!deque || pos < 0 || pos >= deque->size())
        throw std::out_of_range("Iterator out of range");
    // Element index calculation: (front + pos) % capacity
    return deque->data[(deque->front + pos) % deque->capacity];
}

Iterator& Iterator::operator++() {
    ++pos;
    return *this;
}

Iterator Iterator::operator++(int) {
    Iterator tmp(*this);
    ++(*this);
    return tmp;
}

Iterator& Iterator::operator--() {
    --pos;
    return *this;
}

Iterator Iterator::operator--(int) {
    Iterator tmp(*this);
    --(*this);
    return tmp;
}

Iterator& Iterator::operator+=(int n) {
    pos += n;
    return *this;
}

Iterator Iterator::operator+(int n) const {
    Iterator tmp(*this);
    tmp.pos += n;
    return tmp;
}

Iterator& Iterator::operator-=(int n) {
    pos -= n;
    return *this;
}

Iterator Iterator::operator-(int n) const {
    Iterator tmp(*this);
    tmp.pos -= n;
    return tmp;
}

bool Iterator::operator==(const Iterator& other) const {
    return deque == other.deque && pos == other.pos;
}

bool Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}