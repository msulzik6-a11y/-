#include "StudentSession1.h"

StudentSession1::StudentSession1(const char* name, int course, int group, int recordBook, const int grades[GRADES_COUNT])
    : Student(name, course, group, recordBook) {
    for (int i = 0; i < GRADES_COUNT; ++i) {
        setGrade1(i, grades ? grades[i] : 0);
    }
}

StudentSession1::StudentSession1(const StudentSession1& other)
    : Student(other) {
    for (int i = 0; i < GRADES_COUNT; ++i) {
        grades1[i] = other.grades1[i];
    }
}

int StudentSession1::getGrade1(int index) const {
    if (index < 0 || index >= GRADES_COUNT) {
        return 0;
    }
    return grades1[index];
}

void StudentSession1::setGrade1(int index, int grade) {
    if (index >= 0 && index < GRADES_COUNT && grade >= 1 && grade <= 10) {
        grades1[index] = grade;
    }
}

double StudentSession1::averageGrade() const {
    int sum = 0;
    for (int i = 0; i < GRADES_COUNT; ++i) {
        sum += grades1[i];
    }
    return static_cast<double>(sum) / GRADES_COUNT;
}

void StudentSession1::print(std::ostream& os) const {
    Student::print(os);
    os << ", Session 1 grades: [";
    for (int i = 0; i < GRADES_COUNT; ++i) {
        os << grades1[i];
        if (i + 1 < GRADES_COUNT) {
            os << ", ";
        }
    }
    os << "], Avg (session 1): " << averageGrade();
}