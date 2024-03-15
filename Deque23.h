#pragma once
#include "Iterator24.h"
#include <iostream>
#include <string>
#include <vector>
class Deque23
{
public:
    Student* mass;
    int front;
    int last;
    int size;
    int real_size;


    friend class Iterator;
    Deque23() {
        mass = new Student[1];
        mass[0].AverageScore = 0;
        mass[0].FIO = "";
        front = 0;
        last = 0;
        size = 1; //Размер памяти
        real_size = 0; //размер Deque
    }
    Deque23(const Deque23& tmp) { //Копирование
        this->front = tmp.front;
        this->last = tmp.last;
        this->size = tmp.size;
        this->real_size = tmp.real_size;
        this->mass = new Student[size];
        for (int i = 0; i < size; i++) {
            this->mass[i] = tmp.mass[i];
        }
    }
    Deque23(Deque23&& tmp) { //Перемещения
        this->front = tmp.front;
        this->last = tmp.last;
        this->size = tmp.size;
        this->real_size = tmp.real_size;
        this->mass = tmp.mass;
        tmp.mass = nullptr;
    }

    bool empty() {
        if (real_size == 0)
            return true;
        else
            return false;
    }
    bool is_full() {
        if (real_size == size)
            return true;
        else
            return false;

    }
    void push_back(Student add) {
        if (this->is_full()) {
            this->relocate();
            last++;
            mass[last] = add;
            real_size++;
        }
        else if (last == size - 1) {
            last = 0;
            mass[last] = add;
            real_size++;
        }
        else {
            last++;
            mass[last] = add;
            real_size++;
        }
    }

    void push_front(Student add) {
        if (this->is_full()) {
            this->relocate();
            front = size - 1;
            mass[front] = add;
            real_size++;
        }
        else if (front == 0) {
            front = size - 1;
            mass[front] = add;
            real_size++;
        }
        else {
            front--;
            mass[front] = add;
            real_size++;
        }
    }
    int get_size() {
        return real_size;
    }

    void print() {
        cout << endl;
        for (int i = 0; i < real_size; i++) {
            cout << mass[front + i].FIO << "  " << mass[front + i].AverageScore << endl;
        }
        if (last < front) {
            for (int i = 0; i <= last; i++) {
                cout << mass[i].FIO << "  " << mass[i].AverageScore << endl;
            }
        }
    }

    void relocate() {
        Student* tmp = new Student[real_size];
        for (int i = 0; i < real_size - front; i++) {
            tmp[i] = mass[front + i];
        }
        if (last < front)
            for (int i = 0; i <= last; i++) {
                tmp[real_size - front + i] = mass[i];
            }
        size *= 2;
        mass = new Student[size];
        for (int i = 0; i < real_size; i++) {
            mass[i] = tmp[i];
        }
    }

    Deque23& operator =(Deque23& a) {
        if (this != &a) {
            Deque23 tmp(a);
            Swap(tmp);
            return *this;
        }
    }
    Deque23& operator =(Deque23&& a) {
        if (this != &a) {
            Deque23 tmp(forward<Deque23>(a));
            Swap(tmp);
            return *this;
        }
    }

    void Swap(Deque23& tmp) {
        swap(this->front, tmp.front);
        swap(this->last, tmp.last);
        swap(this->size, tmp.size);
        swap(this->real_size, tmp.real_size);
        swap(this->mass, tmp.mass);
    }
    Iterator& begin() {
        Iterator a;
        a.index = front;
        a.deque = this;
        return a;
    }
    Iterator& end() {
        Iterator a;
        a.index = last + 1;
        a.deque = this;
        return a;
    }

    void pop_back() {
        if (!this->empty()) {
            if (last == 0)
                last = size - 1;
            else
                --last;
        }
        --real_size;
    }
    void pop_front() {
        if (!this->empty()) {
            if (front == size - 1)
                front = 0;
            else
                ++front;
        }
        --real_size;
    }



    Student& front_() {
        return mass[front];
    }
    Student& back_() {
        return mass[last];
    }
    Student& at(int a) {
        Student st = { "",0};
        if (front + a < size)
            return mass[front + a];
        else if (a >= real_size) {
            cout << "'at' out of range ERROR!";
            return st;
        }
        else
            return mass[(front + a) % size];
    }
    Student& operator[](int a) {
        Student st{ "",0};
        if (front + a < size)
            return mass[front + a];
        else if (a >= real_size) {
            cout << "'at' out of range ERROR!";
            return st;
        }
        else
            return mass[(front + a) % (size-1)];
    }


};




