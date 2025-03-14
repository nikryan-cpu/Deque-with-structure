#include <iostream>
#include "Deque.h"

int main() {

    Student student1("Н1", 10);
    Student student2("Н2", 20);
    Student student3("Н3", 30);
    Student student4("Н4", 40);

    Deque23 deque;

    deque.push_front(student1);
    deque.push_back(student2);
    deque.push_back(student3);
    deque.push_back(student4);

    std::cout << "Элементы deque:" << std::endl;
    for (const auto& s : deque) {
        std::cout << s << std::endl;
    }

    // pop_front test
    deque.pop_front();
    std::cout << "\nПосле pop_front:" << std::endl;
    for (int i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << std::endl;
    }

    // pop_back test
    deque.pop_back();
    std::cout << "\nПосле pop_back:" << std::endl;
    for (auto it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // clear test
    deque.clear();
    std::cout << "\nПосле clear, размер deque: " << deque.size() << std::endl;

    return 0;
}