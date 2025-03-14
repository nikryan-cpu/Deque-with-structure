#include <iostream>
#include "Deque.h"

int main() {

    Student student1("�1", 10);
    Student student2("�2", 20);
    Student student3("�3", 30);
    Student student4("�4", 40);

    Deque23 deque;

    deque.push_front(student1);
    deque.push_back(student2);
    deque.push_back(student3);
    deque.push_back(student4);

    std::cout << "�������� deque:" << std::endl;
    for (const auto& s : deque) {
        std::cout << s << std::endl;
    }

    // pop_front test
    deque.pop_front();
    std::cout << "\n����� pop_front:" << std::endl;
    for (int i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << std::endl;
    }

    // pop_back test
    deque.pop_back();
    std::cout << "\n����� pop_back:" << std::endl;
    for (auto it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // clear test
    deque.clear();
    std::cout << "\n����� clear, ������ deque: " << deque.size() << std::endl;

    return 0;
}