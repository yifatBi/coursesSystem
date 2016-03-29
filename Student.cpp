//
// Created by yifat biezuner on 29/03/2016.
//

#include <curses.h>
#include "Student.h"
#include <iostream>


using namespace std;

Student::Student():m_name(NULL),m_studentId(DEFUALT_ID) {

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

int Student::initStudentId(const char* id) {
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

Student::Student(const char *name,const char* id):m_name(NULL),m_studentId(initStudentId(id)){
    if(!SetName(name)) {
        m_name = new char(DEFAULT_NAME_LENGTH);
        strcpy(m_name, DEFAULT_NAME);
    }
}

void Student::print() const {
    cout<<"name : "<<m_name<<" id: "<<m_studentId<<endl;
}
