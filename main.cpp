/**
 * Course system with students written by Yifat Biezuner 31/03/2016
 * This program create course and handle it's students.
 * Each student in course have unique id, name, list of grades and measures regarding the his grades like averege and max grade.
 * Also have Data of all students in the program like all grades frequency and max grade.
 */
#include <iostream>
#include "Course.h"
using namespace std;

int main()
{
	//default course
	Course course;
	Student* pStudent1;
	Student student1("yifat",12292);
	Student student2("yifatush",12292);
	cout<<"Default course : "<<endl;
	course.print();
	cout<<"find not exist student expected -1 ---> actual result "<<course.findStudent(23423)<<endl;
	cout<<"find invalid student expected -1 ---> actual result "<<course.findStudent(234233)<<endl;
	cout<<"find student exist in first cell expected 0 ---> actual result "<<course.findStudent(DEFAULT_ID_1)<<endl;
	course.print();
	cout<<"add invalid student id and print --->stay the same"<<endl;
	course.addStudent(456456);
	course.print();
	cout<<"add already exist student and print ---> stay the same"<<endl;
	course.addStudent(DEFAULT_ID_1);
	course.print();
	cout<<"add valid student and print ---> new student added to the course"<<endl;
	course.addStudent(12346);
	course.print();
	cout<<"remove student and print ---> student removed from the course"<<endl;
	course.removeStudent(12346);
	course.print();
	cout<<"remove student that not in the course and print ---> student list stay the course"<<endl;
	course.removeStudent(12346);
	course.print();
	cout<<"switch between students that not in the course and print ---> student list stay the course"<<endl;
	course.switchStudents(12346,12222);
	course.print();
	cout<<"switch between the same student in the course and print ---> student list stay the course"<<endl;
	course.switchStudents(DEFAULT_ID_2,DEFAULT_ID_2);
	course.print();
	cout<<"switch between one student in the course and the other not and print ---> student list stay the course"<<endl;
	course.switchStudents(DEFAULT_ID_1,12346);
	course.print();
	cout<<"switch between 2 students in the course and print ---> students order changed"<<endl;
	course.switchStudents(DEFAULT_ID_1,DEFAULT_ID_2);
	course.print();
	cout<<"switch again between 2 students in the course and print ---> students order return to prev order"<<endl;
	course.switchStudents(DEFAULT_ID_1,DEFAULT_ID_2);
	course.print();
	cout<<"get for not exist student expected null--->actual result ";
	if(course.getStudent(12346)==NULL)
		cout<<"NULL"<<endl;
	cout<<"get for exist student expected different from null--->actual result ";
	if(course.getStudent(DEFAULT_ID_1)!=NULL) {
		(*course.getStudent(DEFAULT_ID_1)).print();
	}
	pStudent1 = (course.getStudent(DEFAULT_ID_1));
	(*pStudent1).addGrade(12);
	cout<<"add grade to student via getStudent"<<endl;
	course.print();
	cout<<"init course with 2equal pointers--->course with 1 student"<<endl;
	Course course2(pStudent1, pStudent1);
	course2.print();
	cout<<"Check is equal expected result false---->"<<boolalpha<<course.isEqual(DEFAULT_ID_1,DEFAULT_ID_2)<<endl;
	cout<<"Check is equal expected result true---->"<<boolalpha<<course.isEqual(DEFAULT_ID_2,DEFAULT_ID_1)<<endl;
	cout<<"Check is equal expected result true---->"<<boolalpha<<course.isEqual(DEFAULT_ID_2,DEFAULT_ID_2)<<endl;
	cout<<"create course is 2 equal student----> only 1 student in the course"<<endl;
	Course course4(NULL, NULL);
	Course course3(student1, student2);
	course3.print();
	cout<<"course init with null pointer expected as default course"<<endl;
	course4.print();
	course3.addStudent(11223);
	course3.addStudent(11224);
	course3.addStudent(11225);
	course3.addStudent(11226);
	cout<<"add students "<<endl;
	course3.print();
	course3.removeStudent(11224);
	course3.removeStudent(11227);
	course3.removeStudent(student1.getId());
	cout<<"after remove:"<<endl;
	course3.print();
	cout<<"find student 11226 enter student "<<boolalpha<<(course3.findStudent(11226)!=NOT_EXIST)<<endl;
	cout<<"get the 11226 student "<<endl;
	(*course3.getStudent(11226)).print();
	(*course3.getStudent(11226)).SetName("New name");
	cout<<"Set name of student 11226:"<<endl;
	course3.print();

	//Test student
	cout<<"student without name default name :";
	Student noName("",12345);
	noName.print();
	cout<<"student with invalid name default values :";
	Student noName1("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",12345);
	noName1.print();
	cout<<"student with invalid id min length default values :";
	Student invalidId("yifat",1234);
	invalidId.print();
	cout<<"student with invalid id max length default values :";
	Student invalidIdMax("yifat",123444);
	invalidIdMax.print();
	cout<<"student with invalid id no digit default values :";
	Student invalidIdDigit("yifat","h12hh");
	invalidIdDigit.print();
	cout<<"student with invalid name and id default values :";
	Student invalidNameAndId("","");
	invalidNameAndId.print();
	cout<<"student valid name yifat Biezuner and id 12092 values :";
	Student studentYifat("yifat Biezuner","12092");
	studentYifat.print();
	studentYifat.addGrade(100);
	studentYifat.addGrade(2);
	studentYifat.addGrade(99);
	studentYifat.addGrade(1);
	studentYifat.print();
	studentYifat.addGrade(100);
	studentYifat.addGrade(-4);
	studentYifat.addGrade(101);
	cout<<"add 100 again and also add -4 and 101---->expected another 100 added"<<endl;
	studentYifat.print();
	cout<<"add grade 100 to another student"<<endl;
	(*course3.getStudent(11226)).addGrade(100);
	cout<<"Measures : average="<<studentYifat.getAverage()<<" Current studentMaxGrade="<<studentYifat.getStudentMaxGrade()<<" have fails="<<
	boolalpha<<studentYifat.isFail()<<" Total max: "<<Student::getMaxGrade()<<endl;
	studentYifat.removeGrade(100);
	studentYifat.print();
	cout<<"Measures : average="<<studentYifat.getAverage()<<" Current studentMaxGrade="<<studentYifat.getStudentMaxGrade()<<" have fails="<<
	boolalpha<<studentYifat.isFail()<<" Total max: "<<Student::getMaxGrade()<<endl;
	studentYifat.removeGrade(2);
	studentYifat.removeGrade(1);
	studentYifat.print();
	cout<<"Measures : average="<<studentYifat.getAverage()<<" Current studentMaxGrade="<<studentYifat.getStudentMaxGrade()<<" have fails="<<
	boolalpha<<studentYifat.isFail()<<" Total max: "<<Student::getMaxGrade()<<endl;
	studentYifat.removeGrade(99);
	studentYifat.print();
	cout<<"Measures : average="<<studentYifat.getAverage()<<" Current studentMaxGrade="<<studentYifat.getStudentMaxGrade()<<" have fails="<<
	boolalpha<<studentYifat.isFail()<<" Total max: "<<Student::getMaxGrade()<<endl;
	(*course3.getStudent(11226)).removeGrade(100);
	cout<<"Only 1 grade of 12 in the system max grade: "<<Student::getMaxGrade()<<endl;
	Student::printGradeFrequency();
	(*pStudent1).removeGrade(12);
	cout<<"No grades in the system max grade : "<<Student::getMaxGrade()<<endl;
	Student::printGradeFrequency();

	return 0;
}