#ifndef ITERATOR_H
#define ITERATOR_H

#include "Student.h"
#include <stdexcept>


class Deque23;

class Iterator {
public:
    // Pointer to container and offset from container start
    Iterator(Deque23* d, int p);
    Iterator();

    Student& operator*() const;

    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    Iterator& operator+=(int n);
    Iterator operator+(int n) const;
    Iterator& operator-=(int n);
    Iterator operator-(int n) const;

    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;

    // Members are exposed for ease of implementation (Iterator is declared as a friend of Deque23 class)
    Deque23* deque;
    int pos; // Position relative to the beginning of the deque
};

#endif // ITERATOR_H