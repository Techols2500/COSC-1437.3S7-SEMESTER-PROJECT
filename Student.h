//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 


#ifndef STUDENT_H 
#define STUDENT_H 


#include "WCS_String.h"
#include "Name.h"
#include "Address.h"
#include "Phone.h"
#include "FixedDigit.h"
#include "FixedString.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  


class Student
{
	//______________________ Methods _______________________________________
public:

	enum		ErrorCodes { NumError, SizeError, End };

	Student();
	~Student();
	void		Read();
	void		Display();
	void		SetName(char *);
	void		SetID(char *);
	void		SetAddress(char *);
	void		SetNumber(char *);
	WCS_String	GetID();
	WCS_String  GetName();
	WCS_String	GetAddress();
	WCS_String	GetNumber();
	int			CompareName(const Student &) const;
	int			CompareID(const Student &) const;
	Student &	Copy(const Student &);

	//______________________ Properties _______________________________________
private:
	Name		Name;
	Address		Address;
	WCS_String	ID;
	Phone		Number;
};

//______________________ Method Definitions _______________________________________

int			ReadFile(Student[]);
void		SortName(Student[], int);
void		SortID(Student[], int);
void		GetName(Student[], int);



#endif 



