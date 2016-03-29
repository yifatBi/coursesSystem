//
// Created by yifat biezuner on 29/03/2016.
//

#include <curses.h>
#include "Student.h"
#include <iostream>


using namespace std;

Student::Student():m_name(NULL),m_studentId(DEFUALT_ID),m_grades(NULL){

}

bool Student::SetName(const char *name) {
    if(name&& strlen(name)<= MAX_NAME_LENGTH)
    {
        if(m_name!=NULL)
            delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy( m_name, name);
        return true;
    }
    return false;

}

int Student::initStudentId(const char* id)const {
    if(strlen(id)==ID_LENGTH){
        for (int i = 0; i < strlen(id); ++i) {
            if(!isdigit(id[i])){
                return DEFUALT_ID;
            }
        }
        return stoi(id);
    }
    return DEFUALT_ID;
}
int Student::initStudentId(int number)const {
    int digits = 0;
    while (number != 0||digits>ID_LENGTH) {
        number /= 10; digits++; }
    if(digits== ID_LENGTH)
        return number;
    return DEFUALT_ID;
}

Student::Student(const char *name,const char* id):m_name(NULL),m_studentId(initStudentId(id)),m_grades(NULL){
    if(!SetName(name)) {
        m_name = new char(DEFAULT_NAME_LENGTH);
        strcpy(m_name, DEFAULT_NAME);
    }
}

void Student::print() const {
    cout<<m_studentId<<" "<<m_name;
    printGradesArray();
    cout<<endl;
}

int Student::maxGrade=0;


Student::~Student() {
    if(m_grades!=NULL)
        delete[] m_grades;
}

bool isValidGrade(const int grade){
    if((MIN_GRADE<=grade)&&(grade<=MAX_GRADE))
        return true;
    return false;
}
bool Student::addGrade(const int grade) {
    if(isValidGrade(grade)){
        if(m_grades==NULL){
            m_grades = new int[1];
            m_grades[0]=grade;
        }else{
            int* tempArray =NULL;
            tempArray= new int[m_maxGradeNum];
            for (int i = 0; i <m_maxGradeNum ; ++i) {
                tempArray[i]=m_grades[i];
            }
            delete[] m_grades;
            m_grades = NULL;
            m_grades = new int[m_maxGradeNum+1];
            for (int i = 0; i <m_maxGradeNum ; ++i) {
                m_grades[i]=tempArray[i];
            }
            m_grades[m_maxGradeNum]=grade;
            delete[] tempArray;
        }
        if(grade>maxGrade)
            Student::maxGrade = grade;
        if(grade>m_maxGrade)
            m_maxGrade = grade;

        numOfGrades++;
        m_maxGradeNum++;
        totalGrade +=grade;
        m_avg = (float)totalGrade/(float)numOfGrades;
        return true;
    }
    return false;
}

void Student::printGradesArray() const {
    bool isFirst = true;
    cout<<'(';
    if(m_grades!=NULL){
        for (int i = 0; i <m_maxGradeNum; ++i) {
            if(isValidGrade(m_grades[i])){
                if(!isFirst)
                    cout<<", ";
               isFirst=false;
               cout<<m_grades[i];
           }
        }
    }
    cout<<')';
        

}

bool Student::removeGrade(const int grade) {
    m_maxGradeNum = numOfGrades;
    bool changeMax = (grade==maxGrade);
    bool changeCurrentMax = (grade==m_maxGrade);
    if(changeMax){
        Student::maxGrade = 0;
    }
    if(changeCurrentMax)
        m_maxGrade = 0;
    for (int i = 0; i <= m_maxGradeNum ; ++i) {
       if(m_grades[i]==grade) {
           m_grades[i]=0;
           totalGrade -=grade;
           --numOfGrades;
           m_avg = (float)totalGrade/(float)numOfGrades;
       }
       else if(changeMax&&m_grades[i]>maxGrade)
           Student::maxGrade = m_grades[i];
       else if(changeCurrentMax&&m_grades[i]>m_maxGrade)
           m_maxGrade = m_grades[i];
    }
    return false;
}

const bool Student::isFail() {
    for (int i = 0; i <m_maxGradeNum; ++i) {
        if(m_grades[i]<PASS_GRADE)
            return true;
    }
    return false;
}

bool Student::isEqual(Student &student) const{
    bool isEqual=true;
    for (int i = 0; i <m_maxGradeNum; ++i) {
        isEqual=false;
        for (int j = 0; j <student.m_maxGradeNum; ++j) {
            if(m_grades[i]==student.m_grades[j]){
                isEqual=true;
            }
        }
           if(!isEqual)
               return false;
    }
    return true;
}

Student::Student(const char *name, int id):m_name(NULL),m_studentId(initStudentId(id)){
    if(!SetName(name)) {
        m_name = new char(DEFAULT_NAME_LENGTH);
        strcpy(m_name, DEFAULT_NAME);
    }
}
