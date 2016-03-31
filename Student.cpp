//
// Created by yifat biezuner on 29/03/2016.
//

#include "Student.h"
#include <iostream>


using namespace std;

Student::Student():m_name(NULL),m_studentId(DEFUALT_ID),m_grades(NULL){
    m_name = new char(DEFAULT_NAME_LENGTH);
    strcpy(m_name, DEFAULT_NAME);
}

bool Student::SetName(const char *name) {
    if(name!=NULL&&strlen(name)>0&&strlen(name)<= MAX_NAME_LENGTH)
    {
        if(m_name!=NULL)
            delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy( m_name, name);
        return true;
    }
    return false;

}

int Student::initStudentId(const char* id,const char* name)const {
    bool isValidName = (name!=NULL&&strlen(name)>0&&strlen(name)<= MAX_NAME_LENGTH);
    if(isValidName&&strlen(id)==ID_LENGTH){
        for (int i = 0; i < strlen(id); ++i) {
            if(!isdigit(id[i])){
                return DEFUALT_ID;
            }
        }
        return atoi(id);
    }
    return DEFUALT_ID;
}

Student::Student(const char *name,const char* id):m_name(NULL),m_studentId(initStudentId(id,name)),m_grades(0){
    if(!SetName(name)||m_studentId==DEFUALT_ID) {
        m_name = new char(DEFAULT_NAME_LENGTH);
        strcpy(m_name, DEFAULT_NAME);
    }
}

void Student::print() const {
    cout<<m_studentId<<" "<<m_name;
    printStudentGradesArray();
    cout<<endl;
}

int Student::maxGrade=0;
int Student::GRADES_FREQUENCY[MAX_OPTIONAL_GRADE]{0};


Student::~Student() {
    if(m_grades!=NULL){
        m_grades=NULL;
        delete[] m_grades;
    }
}

bool isValidGrade(const int grade){
    if((MIN_OPTIONAL_GRADE <= grade)&&(grade <= MAX_OPTIONAL_GRADE))
        return true;
    return false;
}
void Student::addGrade(const int grade) {
    if(isValidGrade(grade)){
        if(m_grades==NULL){
            m_grades = new int[1];
            m_grades[0]=grade;
        }else{
            int* tempArray =NULL;
            tempArray= new int[m_numOfEnteredGrades+1];
            copy(m_grades,m_grades+m_numOfEnteredGrades,tempArray);
            tempArray[m_numOfEnteredGrades] = grade;
            delete[] m_grades;
            m_grades = tempArray;
        }
        //if the grade greater than the current max update the max
        if(grade>maxGrade)
            Student::maxGrade = grade;
        if(grade > m_studentMaxGrade)
            m_studentMaxGrade = grade;
        //Update the measures of the student and update the frequency array
        updateMeasuresAddGrade(grade);
    }
}

void Student::printStudentGradesArray() const {
    bool isFirst = true;
    cout<<'(';
    if(m_grades!=NULL){
        for (int i = 0; i < m_numOfEnteredGrades; ++i) {
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

void Student::removeGrade(const int grade) {
    bool changeMax = (grade==maxGrade);
    bool changeCurrentMax = (grade == m_studentMaxGrade);

    //run on the student grades array if found remove it and update student measures
    for (int i = 0; i <= m_numOfEnteredGrades; ++i) {
       if(m_grades[i]==grade) {
            m_grades[i]=0;
           updateMeasuresRemoveGrade(grade);
       }
    }
    //check if the grade to remove was the max
    if(changeMax&& GRADES_FREQUENCY[grade-1]==0){
        updateMaxGrade();
    }
    //check if the grade to remove was the max of student grades
    if(changeCurrentMax&& m_studentGradesFrequency[grade - 1] == 0){
        updateStudentMaxGrade();
    }
    int a=4;
}

const bool Student::isFail() {
    for (int i = 0; i < m_numOfEnteredGrades; ++i) {
        if(m_grades[i]>0&&m_grades[i]<PASS_GRADE)
            return true;
    }
    return false;
}

bool Student::isEqual(Student student) const{
    bool isEqual=true;
    for (int i = 0; i < m_numOfEnteredGrades; ++i) {
        isEqual=false;
        for (int j = 0; j <student.m_numOfEnteredGrades; ++j) {
            if(m_grades[i]==student.m_grades[j]){
                isEqual=true;
            }
        }
           if(!isEqual)
               return false;
    }
    return true;
}

Student::Student(const char *name, int id): m_name(NULL), m_studentId(expectedStudentId(id,name)), m_grades(0){
    if(m_studentId==DEFUALT_ID||!SetName(name)) {
        m_name = new char(DEFAULT_NAME_LENGTH);
        strcpy(m_name, DEFAULT_NAME);
    }
}

void Student::printGradeFrequency(){
    cout<<"grade freaquency "<<endl;
    for (int i = 0; i < MAX_OPTIONAL_GRADE; ++i) {
        cout<< i+1 <<" : " <<GRADES_FREQUENCY[i]<<endl;
    }
}

void Student::updateMaxGrade() {
    bool isFound=false;
    for (int i = (maxGrade-1); i >= 0&&!isFound; --i) {
        if(GRADES_FREQUENCY[i-1]>0) {
            Student::maxGrade = i;
            isFound=true;
        }
    }
    if(!isFound)
        Student::maxGrade=0;
}

void Student::updateStudentMaxGrade() {
    bool isFound=false;
    for (int i = (m_studentMaxGrade-1); i >= 0&&!isFound; --i) {
        if(m_studentGradesFrequency[i - 1] > 0) {
            m_studentMaxGrade = i;
            isFound=true;
        }
    }
    if(!isFound)
        m_studentMaxGrade=0;
}

int Student::expectedStudentId(const int id,const char* name) {
    bool isValidName = (name!=NULL&&strlen(name)>0&&strlen(name)<= MAX_NAME_LENGTH);
    if(isValidName) {
       int digits = 0;
       int copyNumber = id;
       while (copyNumber != 0 && digits < ID_LENGTH) {
           copyNumber /= 10;
           digits++;
       }
       if (copyNumber == 0&&digits==ID_LENGTH)
           return id;
   }
    return DEFUALT_ID;
}

void Student::updateMeasuresRemoveGrade(const int grade) {
    m_totalGrade -=grade;
    GRADES_FREQUENCY[grade - 1]--;
    m_studentGradesFrequency[grade - 1]--;
    --m_numOfGrades;
    m_avg = (m_numOfGrades==0)?0: (float) m_totalGrade / (float) m_numOfGrades;
}

void Student::updateMeasuresAddGrade(const int grade) {
    m_numOfGrades++;
    m_numOfEnteredGrades++;
    m_totalGrade +=grade;
    GRADES_FREQUENCY[grade - 1]++;
    m_studentGradesFrequency[grade - 1]++;
    m_avg = (float) m_totalGrade / (float) m_numOfGrades;
}
