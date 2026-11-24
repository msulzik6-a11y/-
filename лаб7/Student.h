#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
private:
    static int nextId;
    const int id;
    char* name;
    int course;
    int group;
    const int recordBook;

protected:
    static char* copyString(const char* src);
    virtual void print(std::ostream& os) const;

public:
    Student() = delete;
    Student(const char* name, int course, int group, int recordBook);
    Student(const Student& other);
    Student& operator=(const Student& other) = delete;
    virtual ~Student();

    int getId() const;
    const char* getName() const;
    int getCourse() const;
    int getGroup() const;
    int getRecordBook() const;

    void setName(const char* newName);
    void setCourse(int newCourse);
    void setGroup(int newGroup);

    virtual double averageGrade() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif