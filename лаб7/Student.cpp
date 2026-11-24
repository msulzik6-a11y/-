#include "Student.h"
#include <cstring>

int Student::nextId = 1;

char* Student::copyString(const char* src) {
    if (!src) {
        src = "";
    }
    std::size_t len = std::strlen(src);
    char* dest = new char[len + 1];
    std::strcpy(dest, src);
    return dest;
}

Student::Student(const char* name, int course, int group, int recordBook)
    : id(nextId++), name(copyString(name)), course(course), group(group), recordBook(recordBook) {}

Student::Student(const Student& other)
    : id(nextId++),
      name(copyString(other.name)),
      course(other.course),
      group(other.group),
      recordBook(other.recordBook) {}

Student::~Student() {
    delete[] name;
}

int Student::getId() const {
    return id;
}

const char* Student::getName() const {
    return name;
}

int Student::getCourse() const {
    return course;
}

int Student::getGroup() const {
    return group;
}

int Student::getRecordBook() const {
    return recordBook;
}

void setCourseValue(int& target, int value) {
    if (value > 0) {
        target = value;
    }
}

void Student::setName(const char* newName) {
    char* temp = copyString(newName);
    delete[] name;
    name = temp;
}

void Student::setCourse(int newCourse) {
    setCourseValue(course, newCourse);
}

void Student::setGroup(int newGroup) {
    if (newGroup > 0) {
        group = newGroup;
    }
}

double Student::averageGrade() const {
    return 0.0;
}

void Student::print(std::ostream& os) const {
    os << "ID: " << id
       << ", Name: " << name
       << ", Course: " << course
       << ", Group: " << group
       << ", Record book: " << recordBook;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    student.print(os);
    return os;
}