//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 




#ifndef PHONE_H
#define PHONE_H
#include "WCS_String.h"

class Phone
{
	//______________________ Methods _______________________________________
public:
	Phone();
	~Phone();
	void		Read();
	void		Display();
	void		SetFile(char *);
	WCS_String	GetNumber();

	//______________________ Properties _______________________________________

private:
	WCS_String	Area;
	WCS_String	Number;
};

#endif

