#ifndef _STUDENT_H
#define _STUDENT_H
#include <iostream>
#define MAX_NAME_LENGTH 20
#define DEFAULT_NAME "none"
#define DEFAULT_NAME_LENGTH 5
#define DEFUALT_ID 99999
#define ID_LENGTH 5
#define MIN_OPTIONAL_GRADE 1
#define MAX_OPTIONAL_GRADE 100
#define PASS_GRADE 60


class Student {
private:
    char* m_name;
    const int m_studentId;
    int m_totalGrade = 0;
    static int GRADES_FREQUENCY[MAX_OPTIONAL_GRADE];
    int m_studentGradesFrequency[MAX_OPTIONAL_GRADE];
    int* m_grades;
    float m_avg=0;
    int m_numOfEnteredGrades = 0;
    static int maxGrade;
    int m_studentMaxGrade = 0;
    int m_numOfGrades = 0;
    /**
     * Use for init the Id because it const
     * return the expected student id with the given id
     */
    int initStudentId(const char* id,const char* name)const;
    void printStudentGradesArray()const;
    /**
     * update max grade after max grade has been removed
     * Go from the current max grade down till value if not fount init max with 0
     */
    void updateMaxGrade();
    void updateStudentMaxGrade();
    /**
     * Update student measures after add grade(avg and grades frequency)
     */
    void updateMeasuresAddGrade(const int grade);
    /**
    * Update student measures after remove grade(avg and grades frequency)
    */
    void updateMeasuresRemoveGrade(const int grade);
    public:
    Student();
    Student(const char* name,const char* id);
    Student(const char* name,int id);
    bool SetName(const char* name);
    static int expectedStudentId(const int id,const char* name);
    /**
     * add Grade to the grades array only if valid
     * and update the frequency maxGrade and avg according to the grade
     */
    void addGrade(const int grade);
    /**
     * remove Grade to the grades array only if valid
     * and update the frequency maxGrade and avg according to the grade
     */
    void removeGrade(const int grade);
    /**
     * check if all grades of current student exist in the grades of student given as parameter
     */
    bool isEqual(Student student)const;
    const float getAverage()const{ return m_avg;};
    static int getMaxGrade(){ return maxGrade;}
    int const getStudentMaxGrade()const{ return m_studentMaxGrade;}
    /**
     * Check if Student have Fails grades(Under the PASS_GRADE)
     */
    const bool isFail();
    int getId()const{ return m_studentId;};
    void print()const;
    static void printGradeFrequency();
    ~Student();
};


#endif //_STUDENT_H
