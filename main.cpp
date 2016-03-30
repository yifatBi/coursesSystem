#include <iostream>
#include "Student.h"
#include "Course.h"

using namespace std;

int main()
{
	Course course;
	cout<<"is equal :" <<course.isEqual(11111,22222)<<endl;
	cout<<"is equal :" <<course.isEqual(22222,11111)<<endl;
	cout<<"get student";
	course.getStudent(11111).print();
//	cout<<course.findStudent(12345)<<endl;
//	cout<<course.findStudent(12366)<<endl;
//	course.print();
//	course.switchStudents(12345,67890);
//	course.print();
//	course.removeStudent(12345);
//	cout<<"Find removed student : "<<course.findStudent(12345)<<endl;
	Student student("yifatush","122");
	Student student1("yifatushyifatushyifatushyifatush","12222");
	Student studentinValid("yifatushyifatushyifatushyifatush","hjkio");
	Student studentValid("valid","11111");
	studentValid.isEqual(studentValid);
	student1.print();
	studentinValid.print();
	cout<<"avarage: "<<student.getAverage()<<endl;
	student.addGrade(12);
	student.print();
	cout<<"avarage: "<<student.getAverage()<<endl;
	student.addGrade(15);
	student.addGrade(15);
	student.addGrade(15);
	student.addGrade(15);
	student.addGrade(15);
	cout<<"max grade: "<<Student::getMaxGrade()<<endl;
	student.print();
	cout<<"avarage: "<<student.getAverage()<<endl;
	student.addGrade(15);
	student.addGrade(15);
	student.addGrade(15);
	student.addGrade(15);
	cout<<"is equal to himself with values:"<<student.isEqual(student)<<endl;
	studentValid.print();
	student.print();
	student.addGrade(15);
	student.addGrade(15);
	student.addGrade(15);
	Student::printGradeFrequency();
	cout<<"have fails :";
	std::cout << std::boolalpha << student.isFail() << std::endl;
	student.removeGrade(15);
	cout<<"remove grade 15 :";
	Student::printGradeFrequency();
	student.print();
	cout<<"avarage: "<<student.getAverage()<<endl;
	student.addGrade(0);
	student.print();
	student.removeGrade(13);
	student.print();
	student.removeGrade(12);
	student.print();
	student.removeGrade(12);
	student.print();
	cout<<"No values is fail false :";
	std::cout << std::boolalpha << student.isFail() << std::endl;
	studentValid.addGrade(80);
	cout<<studentValid.getStudentMaxGrade()<<endl;
	cout<<student.getStudentMaxGrade()<<endl;
	cout<<student.getMaxGrade()<<endl;
	cout<<"No failed false :";
	std::cout << std::boolalpha << studentValid.isFail() << std::endl;
	studentValid.addGrade(15);
	cout<<"max grade: "<<Student::getMaxGrade()<<endl;
	cout<<"isEqual false:"<<studentValid.isEqual(student)<<endl;
	cout<<"isEqual true:"<<student.isEqual(studentValid)<<endl;
	studentValid.print();
	Student::printGradeFrequency();
	cout<<"Max Grade:"<<Student::getMaxGrade()<<endl;
	student.addGrade(15);
	student.print();
	Course course2(student,studentValid);
	cout<<"isEqual true:"<<student.isEqual(studentValid)<<endl;
	cout<<"isEqual true:"<<course2.isEqual(student.getId(),studentValid.getId())<<endl;
	cout<<"isEqual false:"<<studentValid.isEqual(student)<<endl;
	cout<<"isEqual false:"<<course2.isEqual(studentValid.getId(),student.getId())<<endl;


	return 0;
}