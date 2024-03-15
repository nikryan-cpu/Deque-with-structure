#pragma once
#include <string>
using namespace std;
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

    Iterator& operator +=(int a) {
        index += a;
        return *this;
    }

    Iterator operator++ (int)
    {
        Iterator copy{ *this };
        ++(*this);
        return copy;
    }

    Iterator operator-- (int)
    {
        Iterator copy{ *this };
        --(*this);
        return copy;
    }

    Iterator& operator -=(int a) {
        index -= a;
        return *this;
    }

    Iterator& operator +(int& a) {
        Iterator b;
        b.deque = this->deque;
        b.index = this->index + a;
        return b;
    }

    Iterator& operator -(int& a) {
        Iterator b;
        b.deque = this->deque;
        b.index = this->index - a;
        return b;
    }

    friend Student& operator *(const Iterator& a);

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


