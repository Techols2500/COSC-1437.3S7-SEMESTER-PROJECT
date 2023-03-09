//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 

#include <iostream>

using namespace std;


#include "Student.h" 
#include "WCS_String.h"  


void main()
{

	Student		Test;
	Student		Class1[26];
	Student		Class2[26];

	fstream		MyFile;

	int			i;
	int			count;

	try
	{
		cout << "Enter EOF into the First Name to finalize" << endl;
		for (i = 0; i < 25; i++)
		{
			cout << "Student Number: " << i + 1 << endl;
			Class1[i].Read();
		}
	}
	catch (WCS_String End)
	{
		cout << "EOF entered" << endl;
	}
	system("cls");

	cout << "Number of students: " << i << endl;


	for (count = 0; count < i; count++)
	{
		Class1[count].Display();
		cout << endl;
	}

	GetName(Class1, i);
	cout << "\tData input into Student Attendence " << endl;

	SortName(Class1, i);

	for (count = 0; count < i; count++)
	{
		Class1[count].Display();
		cout << endl;
	}

	SortID(Class1, i);

	for (count = 0; count < i; count++)
	{
		Class1[count].Display();
		cout << endl;
	}

	i = ReadFile(Class2);
	cout << "Number of students: " << i << endl;
	for (count = 0; count < i; count++)
	{
		Class2[count].Display();
		cout << endl;
	}

}







