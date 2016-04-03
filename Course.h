#ifndef _COURSE_H
#define _COURSE_H
#include "Student.h"
#define DEFAULT_STUDENT_COURSE_NAME "courseStudent"
#define STUDENT_DEFAULT_ARRAY_SIZE 2
#define NOT_EXIST -1
#define DEFAULT_NAME_1 "auto1"
#define DEFAULT_NAME_2 "auto2"
#define DEFAULT_ID_1 12345
#define DEFAULT_ID_2 67890
using namespace std;

class Course {
    Student ** m_students;
    int m_studentsNum = 2;
    /**
     * create a student with the given values and return it as reference
     */
    Student* createStudent(const char* name,const int id)const;
    /**
     * init students array with the default values
     */
    void initDefault();
public:
    /**
     * find the student according id from the student list of the course
     * return NOT_EXIST value if didn't found
     */
    const int findStudent(const int idToFind)const;
    /**
     * return the student from the list if not exist return NULL
     */
    Student* getStudent(const int idToFind)const;
    /**
     * if student exist according to given id remove it from the list of students in this course
     */
    void removeStudent(const int idToRemove);
    /**
     * If valid Id and this student is not already part of this course
     * add student with the given id and generated name(according to default name and number of students in this course)
     * to students array
     */
    void addStudent(const int idToAdd);
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
    ~Course();
    Course(Student& student1,Student&student2);
    Course(Student* student1,Student* student2);
};


#endif //_COURSE_H
