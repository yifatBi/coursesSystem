//
// Created by yifat biezuner on 29/03/2016.
//

#ifndef TIRGUL4_EX_AND_SOL_COURSE_H
#define TIRGUL4_EX_AND_SOL_COURSE_H


#include "Student.h"
#include <iostream>
#include <string.h>
using namespace std;
#define STUDENT_DEFAULT_ARRAY_SIZE 2

class Course {
    Student ** m_students;
    Student default1;
    Student default2;
    Student temp;
    int studentsNum = 2;
public:
    /**
     * find the student according id from the student list of the course
     * retuen NOT_EXIST value if didn't found
     */
    const int findStudent(const int idToFind)const;
    /**
     * return the student from the list if not exist return NULL
     */
    const Student getStudent(const int idToFind)const;
    /**
     * if student exist according to given id remove it from the list
     */
    void removeStudent(const int idToRemove);
    /**
     * if both student exist in this course switch places between them
     */
    void switchStudents(const int firstId,const int secondId);
    /**
     * Check if two students exist in this course and if so compare between them(Student compare)
     */
    const bool isEqual(const int firstId,const int secondId)const;
    void print()const;
    Course();
    Course(Student& student1,Student&student2);
};


#endif //TIRGUL4_EX_AND_SOL_COURSE_H
