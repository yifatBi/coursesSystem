//
// Created by yifat biezuner on 29/03/2016.
//

#ifndef TIRGUL4_EX_AND_SOL_STUDENT_H
#define TIRGUL4_EX_AND_SOL_STUDENT_H
#include <string.h>
#define MAX_NAME_LENGTH 20
#define DEFAULT_NAME "none"
#define DEFAULT_NAME_LENGTH 5
#define DEFUALT_ID 99999
#define ID_LENGTH 5
#define MIN_GRADE 1
#define MAX_GRADE 100
#define GRADES_FREQ_SIZE 100
#define PASS_GRADE 60


class Student {
private:
    char* m_name;
    const int m_studentId;
    int totalGrade = 0;
    static int m_grades_frequancy[GRADES_FREQ_SIZE];
    int* m_grades;
    float m_avg=0;
    int m_maxGradeNum = 0;
    static int maxGrade;
    int m_maxGrade = 0;
    int numOfGrades = 0;
    void printGradesArray()const;
    public:
    Student();
    Student(const char* name,const char* id);
    bool SetName(const char* name);
    int initStudentId(const char* id);
    bool addGrade(const int grade);
    bool removeGrade(const int grade);
    bool isEqual(Student& student);
    const float getAverage()const{ return m_avg;};
    static int getMaxGrade(){ return maxGrade;}
    int const getStudentMaxGrade()const{ return m_maxGrade;}
    const bool isFail();
    void print()const;
    ~Student();
};


#endif //TIRGUL4_EX_AND_SOL_STUDENT_H
