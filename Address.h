//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 

#ifndef ADDRESS_H 
#define ADDRESS_H 

#include "WCS_String.h"


class Address
{
	//______________________ Methods _______________________________________
public:
	Address();
	~Address();
	void		Read();
	void		Display();
	void		SetFile(char *);
	WCS_String	GetAddress();

	//______________________ Properties _______________________________________
private:
	WCS_String		Street;
	WCS_String		City;
	WCS_String		State;
	WCS_String		Zip;
};

//______________________ Method Definitions _______________________________________



#endif 



