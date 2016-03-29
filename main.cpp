#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
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
	cout<<"have fails :";
	std::cout << std::boolalpha << student.isFail() << std::endl;
	student.removeGrade(15);
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
	cout<<"isEqual true:"<<student.isEqual(studentValid);
	studentValid.print();
	student.addGrade(15);
	student.print();
	cout<<"isEqual true:"<<student.isEqual(studentValid)<<endl;
	cout<<"isEqual false:"<<studentValid.isEqual(student)<<endl;


	return 0;
}