#include "Student.h"

int main()
{
	Student student("yifatush","122");
	Student student1("yifatushyifatushyifatushyifatush","12222");
	Student studentinValid("yifatushyifatushyifatushyifatush","hjkio");
	Student studentValid("valid","11111");
//	BookTitle book;
//	Journal journal;
//	WorkbookTitle workbook;
//	ResearchTitle research;

	student.print();
	student1.print();
	studentinValid.print();
	studentValid.print();
//	book.SetName("The Green Monkey");
//	book.SetAuthor( "John Grishem" );
//	book.SetAddition( 2 );
//	book.Print();
//
//	journal.SetName( "Blazer" );
//	journal.SetAuthor( "Yediot Aharonot" );
//	journal.SetYear( 1855 );
//	journal.Print();
//
//	workbook.SetName( "Learn c++" );
//	workbook.SetAuthor( "Jonny Jonny" );
//	workbook.SetCourse( "OOP" );
//	workbook.Print();
//
//	research.SetName( "Robotics" );
//	research.SetAuthor( "Someone" );
//	research.SetSupervisor( "Somebody" );
//	research.Print();
//
//	BookTitle book1( "The Green Monkey", "John Grishem", 2 );
//	Journal journal1( "Blazer", "Yediot Aharonot", 1855 );
//	WorkbookTitle workbook1( "Learn c++", "Jonny Jonny", "OOP" );
//	ResearchTitle research1( "Robotics", "Someone", "Somebody" );
//
//	book1.Print();
//	journal1.Print();
//	workbook1.Print();
//	research1.Print();

	return 0;
}