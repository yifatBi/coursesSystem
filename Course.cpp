//
// Created by yifat biezuner on 29/03/2016.
//

#include "Course.h"


Course::Course():m_students(NULL) {
    m_students = new Student*[STUDENT_DEFAULT_ARRAY_SIZE];
    m_students[0]= createStudent(DEFAULT_NAME_1, DEFAULT_ID_1);
    m_students[1]= createStudent(DEFAULT_NAME_2, DEFAULT_ID_2);
}

const int Course::findStudent(const int idToFind) const {
    for (int i = 0; i < studentsNum; ++i) {
      if(m_students[i]!=NULL&&(*m_students[i]).getId()==idToFind) {
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
    }

}

void Course::switchStudents(const int firstId, const int secondId) {
    int firstIndex =findStudent(firstId);
    int secondIndex =findStudent(secondId);
    //check that the student is different and both id's exist in the course
    if(firstId!=secondId&&(firstIndex!=NOT_EXIST)
       &&(secondIndex!=NOT_EXIST)){
        Student * temp = m_students[firstIndex];
        m_students[firstIndex]= m_students[secondIndex];
        m_students[secondIndex] = temp;
    }
}

void Course::print() const {
    int lastIndex=0;
    for (int i = 0; i < studentsNum; ++i) {
        if(m_students[i]!=NULL){
         cout<< lastIndex<<" ";
            (m_students[i])->print();
            lastIndex++;
        }else{
            lastIndex=i;
        }
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

Student* Course::getStudent(const int idToFind) const {
    int index = findStudent(idToFind);
    if(index!=NOT_EXIST)
        return m_students[index];
    return NULL;
}

Course::Course(Student &student1, Student &student2) {
    m_students = new Student*[STUDENT_DEFAULT_ARRAY_SIZE];
    m_students[0]= &student1;
    m_students[1]= &student2;
}

Student *Course::createStudent(const char *name, const int id) const {
    return new Student[1]{Student(name,id)};
}
Student Course::createStudent2(const char *name, const int id) const {
    return Student(name,id);
}

void Course::addStudent(const int idToAdd) {
    int expectedId = Student::expectedStudentId(idToAdd);
    //Check that the student not exist and the id is valid
    if(getStudent(idToAdd)==NULL&& expectedId != DEFUALT_ID){
        Student** tempStudentArray = new Student*[studentsNum+1];
        copy(m_students,m_students+studentsNum,tempStudentArray);
        tempStudentArray[studentsNum] = createStudent("",idToAdd);
        delete[] m_students;
        m_students = tempStudentArray;
        studentsNum++;
    }
}

