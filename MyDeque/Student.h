#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

struct Student {
    std::string FIO;
    int AverageScore;

    Student(const std::string& fio = "", int avg = 0)
        : FIO(fio), AverageScore(avg) {}
};

inline std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.FIO << "  " << s.AverageScore;
    return os;
}

#endif