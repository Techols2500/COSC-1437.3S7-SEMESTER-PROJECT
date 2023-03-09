//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 


#ifndef FIXED_STRING_H
#define FIXED_STRING_H

#include <iostream>
using namespace std;

template <int length>
class FixedString
{
public:
	//CONSTRUCTORS
	FixedString(); //default constructor
	FixedString(const char *); //overloaded constructor
	FixedString(FixedString <length> &);	// copy constructor
	virtual ~FixedString(); //destructor

							//METHOD PROTOTYPES
	FixedString <length> & Copy(FixedString <length> &);
	FixedString <length> & Copy(const char *);
	FixedString <length> & operator = (FixedString <length> &);
	FixedString <length> & operator = (const char *);

protected:
	char Chars[length + 1];
	int size = length;
};

//CONSTRUCTORS/DESTRUCTORS BELOW
template <int length>
FixedString<length>::FixedString()
{
	fill(Chars, Chars + length, ' ');
	Chars[length] = '\0';
}

template <int length>
FixedString<length>::FixedString(const char * c)
{
	int strlength = strlen(c);

	if (strlength != length)
	{
		throw - 1;
	}
	else
	{
		strcpy(Chars, c);
	}
}

template <int length>
FixedString <length>::FixedString(FixedString <length> & c)
{
	strcpy(Chars, c.Chars);
}

template <int length>
FixedString <length>::~FixedString()
{
}


//METHODS BELOW
template <int length>
FixedString<length> & FixedString <length>::Copy(FixedString <length> & c)
{
	strcpy(Chars, c.Chars);
	return *this;
}

template <int length>
FixedString<length> & FixedString<length>::Copy(const char * c)
{
	int strlength = strlen(c);
	if (strlength != length)
	{
		throw - 2;
	}
	else
	{
		strcpy(Chars, c);
	}
}

template <int length>
FixedString<length> & FixedString <length>::operator = (FixedString <length> & c)
{
	Copy(c);
	return *this;
}

template <int length>
FixedString<length> & FixedString <length>::operator = (const char * c)
{
	Copy(c);
	return *this;
}

#endif

