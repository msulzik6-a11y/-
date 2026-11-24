#include "StudentSession2.h"

StudentSession2::StudentSession2(const char* name, int course, int group, int recordBook,
                                 const int s1Grades[StudentSession1::GRADES_COUNT],
                                 const int s2Grades[GRADES_COUNT])
    : StudentSession1(name, course, group, recordBook, s1Grades) {
    for (int i = 0; i < GRADES_COUNT; ++i) {
        setGrade2(i, s2Grades ? s2Grades[i] : 0);
    }
}

StudentSession2::StudentSession2(const StudentSession2& other)
    : StudentSession1(other) {
    for (int i = 0; i < GRADES_COUNT; ++i) {
        grades2[i] = other.grades2[i];
    }
}

int StudentSession2::getGrade2(int index) const {
    if (index < 0 || index >= GRADES_COUNT) {
        return 0;
    }
    return grades2[index];
}

void StudentSession2::setGrade2(int index, int grade) {
    if (index >= 0 && index < GRADES_COUNT && grade >= 1 && grade <= 10) {
        grades2[index] = grade;
    }
}

double StudentSession2::averageGrade() const {
    int sum = 0;
    for (int i = 0; i < StudentSession1::GRADES_COUNT; ++i) {
        sum += getGrade1(i);
    }
    for (int i = 0; i < GRADES_COUNT; ++i) {
        sum += grades2[i];
    }
    int totalCount = StudentSession1::GRADES_COUNT + GRADES_COUNT;
    return static_cast<double>(sum) / totalCount;
}

void StudentSession2::print(std::ostream& os) const {
    StudentSession1::print(os);
    os << ", Session 2 grades: [";
    for (int i = 0; i < GRADES_COUNT; ++i) {
        os << grades2[i];
        if (i + 1 < GRADES_COUNT) {
            os << ", ";
        }
    }
    os << "], Avg (year): " << averageGrade();
}