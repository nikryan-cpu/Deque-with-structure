#pragma once
#include <string>
struct Student {
    string FIO;
    int AverageScore;
};
class Deque23;
class Iterator {
public:
    Deque23* deque;
    int index;
    friend class Deque23;

    Iterator() {
        deque = nullptr;
        index = 0;
    }

    Iterator(Deque23* a, int b) {
        deque = a;
        index = b;
    }

    Iterator& operator++() {
        index++;
        return *this;
    }

    Iterator& operator--() {
        index--;
        return *this;
    }

    Student& operator *() {
        return deque->mass[(deque->front + index) % deque->real_size];
    }

    Iterator& operator=(Iterator& a) {
        this->index = a.index;
        this->deque = a.deque;
        return *this;
    }

    bool operator ==(const Iterator& e16)
    {
        return deque == e16.deque && index == e16.index;
    }

    bool operator !=(const Iterator& e16)
    {
        return deque != e16.deque || index != e16.index;
    }
};

