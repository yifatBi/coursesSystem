//
// Created by yifat biezuner on 29/03/2016.
//

#ifndef TIRGUL4_EX_AND_SOL_COURSE_H
#define TIRGUL4_EX_AND_SOL_COURSE_H


#include "Student.h"
#include <iostream>
using namespace std;
#define STUDENT_DEFAULT_ARRAY_SIZE 2

class Course {
    Student ** m_students;
    Student default1;
    Student default2;
    Student temp;
    int studentsNum = 2;
public:
    const int findStudent(const int idToFind)const;
    void removeStudent(const int idToRemove);
    void switchStudents(const int firstId,const int secondId);
    const bool isEqual(const int firstId,const int secondId)const;
    void print()const;
    Course();
};


#endif //TIRGUL4_EX_AND_SOL_COURSE_H
