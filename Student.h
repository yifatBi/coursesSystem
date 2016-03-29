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


class Student {
    char* m_name;
    const int m_studentId;
    public:
    Student();
    Student(const char* name,const char* id);
    bool SetName(const char* name);
    int initStudentId(const char* id);
    void print()const;
};


#endif //TIRGUL4_EX_AND_SOL_STUDENT_H
