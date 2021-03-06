#include "Course.h"
#include <string>
Course::Course():m_students(NULL) {
    m_students = new Student*[STUDENT_DEFAULT_ARRAY_SIZE];
    initDefault();
}

Course::Course(Student *student1, Student *student2) {
    m_students = new Student*[STUDENT_DEFAULT_ARRAY_SIZE];
    //if null pointer call the default init
    if(student1==NULL&&student2==NULL){
        initDefault();
    }else {
        m_studentsNum=0;
        //if pointer different from null init with the pointer else init null
        if(student1 != NULL) {
            m_students[0] = student1;
            m_studentsNum++;
        }else{
            m_students[0] = NULL;
        }
        m_students[1] = NULL;
        if (student1 != NULL && student2 != NULL && (*student1).getId() != (*student2).getId()){
            m_students[1] = student2;
            m_studentsNum++;
        }
    }
}

Course::Course(Student &student1, Student &student2) {
    m_students = new Student*[STUDENT_DEFAULT_ARRAY_SIZE];
    m_students[0]= &student1;
    m_students[1]= NULL;
    m_studentsNum = 1;
    //add second student only if different from the first one
    if(student1.getId()!= student2.getId()){
        m_students[1]= &student2;
        m_studentsNum++;
    }
}

const int Course::findStudent(const int idToFind) const {
    for (int i = 0; i < m_studentsNum; ++i) {
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
    for (int i = 0; i < m_studentsNum; ++i) {
        if(m_students[i]!=NULL){
         cout<< lastIndex<<" ";
            (m_students[i])->print();
            lastIndex++;
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


Student *Course::createStudent(const char *name, const int id) const {
    return new Student[1]{Student(name,id)};
}

void Course::addStudent(const int idToAdd) {
    int expectedId = Student::expectedStudentId(idToAdd,DEFAULT_STUDENT_COURSE_NAME);
    //Check that the student not exist and the id is valid
    //add dynamically element to the grades
    if(getStudent(idToAdd)==NULL&& expectedId != DEFUALT_ID){
        Student** tempStudentArray = new Student*[m_studentsNum + 1];
        copy(m_students, m_students + m_studentsNum, tempStudentArray);
        //generate name of next student according is number in the course
        int nextStudentNum = m_studentsNum+1;
        //Generate the student name according to DEFAULT_STUDENT_COURSE_NAME and number of student in the course
        char* studentName =new char[strlen(DEFAULT_STUDENT_COURSE_NAME)+1+strlen(to_string(nextStudentNum).c_str())];
        strcpy(studentName,DEFAULT_STUDENT_COURSE_NAME);
        strcat(studentName, to_string(nextStudentNum).c_str());
        tempStudentArray[m_studentsNum] = createStudent(studentName, idToAdd);
        delete[] m_students;
        m_students = tempStudentArray;
        m_studentsNum++;
    }
}


void Course::initDefault() {
    m_students[0]= createStudent(DEFAULT_NAME_1, DEFAULT_ID_1);
    m_students[1]= createStudent(DEFAULT_NAME_2, DEFAULT_ID_2);
}

Course::~Course() {
    if(m_students!=NULL)
        delete[] m_students;
}
