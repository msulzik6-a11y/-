#ifndef STUDENT_SESSION_2_H
#define STUDENT_SESSION_2_H

#include "StudentSession1.h"

class StudentSession2 : public StudentSession1 {
public:
    static const int GRADES_COUNT = 5;

private:
    int grades2[GRADES_COUNT];

protected:
    void print(std::ostream& os) const override;

public:
    StudentSession2() = delete;
    StudentSession2(const char* name, int course, int group, int recordBook,
                    const int s1Grades[StudentSession1::GRADES_COUNT],
                    const int s2Grades[GRADES_COUNT]);
    StudentSession2(const StudentSession2& other);
    ~StudentSession2() override = default;

    int getGrade2(int index) const;
    void setGrade2(int index, int grade);

    double averageGrade() const override;
};

#endif