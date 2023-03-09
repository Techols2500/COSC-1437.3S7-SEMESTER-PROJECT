//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 

#ifndef NAME_H 
#define NAME_H 

#include "WCS_String.h"

class Name
{
	//______________________ Methods _______________________________________
public:
	Name();
	~Name();

	void		Read();
	void		Display();
	void		SetFile(char *);
	int			CompareName(const Name &) const;
	WCS_String	GetName();




	//______________________ Properties _______________________________________
private:
	WCS_String		First;
	WCS_String		Middle;
	WCS_String		Last;


};

//______________________ Method Definitions _______________________________________



#endif



