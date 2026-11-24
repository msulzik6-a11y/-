#ifndef STUDENT_SESSION_1_H
#define STUDENT_SESSION_1_H

#include "Student.h"

class StudentSession1 : public Student {
public:
    static const int GRADES_COUNT = 4;

private:
    int grades1[GRADES_COUNT];

protected:
    void print(std::ostream& os) const override;

public:
    StudentSession1() = delete;
    StudentSession1(const char* name, int course, int group, int recordBook, const int grades[GRADES_COUNT]);
    StudentSession1(const StudentSession1& other);
    ~StudentSession1() override = default;

    int getGrade1(int index) const;
    void setGrade1(int index, int grade);

    double averageGrade() const override;
};

#endif