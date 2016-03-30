//
// Created by yifat biezuner on 29/03/2016.
//

#include "Course.h"
#define NOT_EXIST -1
#define DEFAULT_NAME_1 "auto1"
#define DEFAULT_NAME_2 "auto2"
//#define DEFAULT_ID_1 12345
//#define DEFAULT_ID_2 67890
#define DEFAULT_ID_1 11111
#define DEFAULT_ID_2 22222

Course::Course():default1(DEFAULT_NAME_1, DEFAULT_ID_1),default2(DEFAULT_NAME_2, DEFAULT_ID_2),m_students(NULL) {
    m_students = new Student*[STUDENT_DEFAULT_ARRAY_SIZE]{NULL};
    m_students[0]=NULL;
    m_students[1]=NULL;
    m_students[0]= &default1;
    m_students[1]= &default2;
}

const int Course::findStudent(const int idToFind) const {
    for (int i = 0; i < studentsNum; ++i) {
      if((*m_students[i]).getId()==idToFind) {
          return i;
      }
    }
    return NOT_EXIST;
}

void Course::removeStudent(const int idToRemove) {
    int indexToRemove = findStudent(idToRemove);
    if(indexToRemove!=NOT_EXIST) {
        m_students[indexToRemove] = NULL;
        delete (m_students[indexToRemove]);
        studentsNum--;
    }

}

void Course::switchStudents(const int firstId, const int secondId) {
    int firstIndex =findStudent(firstId);
    int secondIndex =findStudent(secondId);
    if(firstId!=secondId&&(firstIndex!=NOT_EXIST)
       &&(secondIndex!=NOT_EXIST)){
        Student * temp = m_students[firstIndex];
        m_students[firstIndex]= m_students[secondIndex];
        m_students[secondIndex] = temp;
    }
}

void Course::print() const {
    for (int i = 0; i < studentsNum; ++i) {
       cout<< i<<" ";
        (m_students[i])->print();
    }
}

const bool Course::isEqual(const int firstId, const int secondId) const {
    int firstIndex =findStudent(firstId);
    int secondIndex =findStudent(secondId);
    if(firstId==secondId)
        return true;
    if((firstIndex!=NOT_EXIST)&&(secondIndex!=NOT_EXIST)) {
        return (*m_students[firstIndex]).isEqual(*m_students[secondIndex]);
    }
    return false;
}

const Student Course::getStudent(const int idToFind) const {
    int index = findStudent(idToFind);
    if(index!=NOT_EXIST)
        return *m_students[index];
    return Student();
}

Course::Course(Student &student1, Student &student2) {
    m_students = new Student*[STUDENT_DEFAULT_ARRAY_SIZE]{NULL};
    m_students[0]=NULL;
    m_students[1]=NULL;
    m_students[0]= &student1;
    m_students[1]= &student2;
}
