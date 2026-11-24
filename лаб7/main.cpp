#include <iostream>
#include "Student.h"
#include "StudentSession1.h"
#include "StudentSession2.h"

double averageGroupSession1(StudentSession1* const* arr, int size, int targetGroup) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != nullptr && arr[i]->getGroup() == targetGroup) {
            sum += arr[i]->StudentSession1::averageGrade();
            ++count;
        }
    }
    return (count > 0) ? (sum / count) : 0.0;
}

double averageGroupSession2(StudentSession2* const* arr, int size, int targetGroup) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != nullptr && arr[i]->getGroup() == targetGroup) {
            sum += arr[i]->averageGrade();
            ++count;
        }
    }
    return (count > 0) ? (sum / count) : 0.0;
}

double averagePointerArray(Student* const* arr, int size) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != nullptr) {
            sum += arr[i]->averageGrade();
            ++count;
        }
    }
    return (count > 0) ? (sum / count) : 0.0;
}

int main() {
    int g1A[4] = {8, 9, 7, 10};
    int g1B[4] = {6, 7, 8, 7};
    int g2A[5] = {9, 9, 8, 10, 9};
    int g2B[5] = {7, 8, 6, 7, 8};

    Student s0("Ivan Petrov", 1, 101, 10001);
    StudentSession1 s1("Anna Smirnova", 1, 101, 10002, g1A);
    StudentSession1 s1Copy(s1);
    s1Copy.setName("Anna Smirnova (copy)");
    s1Copy.setGrade1(2, 9);

    StudentSession2 s2("Dmitry Volkov", 1, 101, 10003, g1B, g2A);
    StudentSession2 s2Other("Elena Sokolova", 1, 102, 10004, g1A, g2B);

    std::cout << s0 << "\n";
    std::cout << s1 << "\n";
    std::cout << s1Copy << "\n";
    std::cout << s2 << "\n";
    std::cout << s2Other << "\n\n";

    StudentSession1* session1List[3] = {&s1, &s1Copy, &s2};
    StudentSession2* session2List[2] = {&s2, &s2Other};

    int targetGroup = 101;
    std::cout << "Group " << targetGroup << " average after session 1: "
              << averageGroupSession1(session1List, 3, targetGroup) << "\n";
    std::cout << "Group " << targetGroup << " average after two sessions: "
              << averageGroupSession2(session2List, 2, targetGroup) << "\n\n";

    const int ARR_SIZE = 3;
    Student* polymorphicArr[ARR_SIZE] = {
        new Student("Freshman Base", 1, 101, 20001),
        new StudentSession1("Session 1 Student", 1, 101, 20002, g1A),
        new StudentSession2("Session 2 Student", 1, 101, 20003, g1B, g2A)
    };

    for (int i = 0; i < ARR_SIZE; ++i) {
        std::cout << *polymorphicArr[i] << "\n";
    }
    std::cout << "Average grade across polymorphic pointer array: "
              << averagePointerArray(polymorphicArr, ARR_SIZE) << "\n";

    for (int i = 0; i < ARR_SIZE; ++i) {
        delete polymorphicArr[i];
    }

    return 0;
}