//
// Created by yifat biezuner on 29/03/2016.
//

#include <curses.h>
#include "Student.h"
#include <iostream>


using namespace std;

Student::Student():m_name(NULL),m_studentId(NULL) {

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

bool Student::SetStudentId(const char* id) {
    if(strlen(id)==5){
        for (int i = 0; i < strlen(id); ++i) {
            if(!isdigit(id[i])){
                return false;
            }
        }
        if( m_studentId!=NULL)
            delete[] m_studentId;
        m_studentId = new char[strlen(id) + 1];
        strcpy( m_studentId, id);
        return true;
    }
    return false;
}

Student::Student(const char *name,const char* id):m_name(NULL),m_studentId(NULL){
    if(!SetName(name)) {
        m_name = new char(DEFAULT_NAME_LENGTH);
        strcpy(m_name, DEFAULT_NAME);
    }
    if(!SetStudentId(id)) {
        m_studentId = new char(ID_LENGTH);
        strcpy(m_studentId, DEFUALT_ID);
    }
}

void Student::print() const {
    cout<<"name : "<<m_name<<" id: "<<m_studentId<<endl;
}
