//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 




#ifndef FIXED_DIGIT_H
#define FIXED_DIGIT_H

#include "FixedString.h"
#include <array>

template <int length>
class DigitString : public FixedString <length>
{
public:

	//CONSTRUCTORS
	DigitString(); //default constructor
	DigitString(const char *); //overloaded constructor
	DigitString(const DigitString <length> &);	// copy constructor
	~DigitString(); //destructor

					//METHOD PROTOTYPES
	int Compare(const DigitString <length> &);
	int Compare(const char*); //A string of characters
	DigitString & Copy(const DigitString<length> &);
	DigitString & Copy(const char*);

	//READ/WRITE PROTOTYPES
	istream & Read(istream & = cin);
	fstream & Read(fstream &);
	fstream & Write(fstream &);
	ostream & Display(ostream &);

	//OVERLOADED COMPARE OPERATORS
	DigitString &		operator =			(const DigitString <length> &);
	DigitString &		operator =			(const char *);
	bool	operator ==			(const DigitString <length> &);
	bool	operator ==			(const char *);
	bool	operator >			(const DigitString <length> &);
	bool	operator >			(const char *);
	bool	operator >=			(const DigitString <length> &);
	bool	operator >=			(const char *);
	bool	operator <			(const DigitString <length> &);
	bool	operator <			(const char *);
	bool	operator <=			(const DigitString <length> &);
	bool	operator <=			(const char *);
	bool	operator !=			(const DigitString <length> &);
	bool	operator !=			(const char *);

};

typedef DigitString <5>		Zip;
typedef DigitString <9>		ID;
typedef DigitString <3>		Area;
typedef DigitString <7>		Number;

//CONSTRUCTORS/DESTRUCTORS BELOW
template <int length>
DigitString<length>::DigitString()
{
	fill(Chars, Chars + length, '0');
	Chars[length] = '\0';
}

template<int length>
DigitString<length>::DigitString(const char * c) : FixedString<length>(c)
{
	if (!(isDigit(c)))
	{
		throw - 3;
	}
	//exception if you try to make a digit string that does NOT contain numbers aka letters
}

template<int length>
DigitString<length>::DigitString(const DigitString <length> & c) : FixedString<length>(c.Chars)
{
}

template<int length>
DigitString<length>::~DigitString()
{
}

//METHODS BELOW
template<int length>
int DigitString<length>::Compare(const DigitString <length> & c)
{
	int result = strcmp(Chars, c.Chars);
	return result;
}

template<int length>
int DigitString<length>::Compare(const char* c) //A String of characters
{
	int result = strcmp(Chars, c);
	return result;
}

template<int length>
DigitString<length> & DigitString<length>::Copy(const DigitString<length> & c)
{
	FixedString<legnth>::Copy(c.Chars);
	return *this;
}

template<int length>
DigitString<length> & DigitString<length>::Copy(const char* c)
{
	if (!(isDigit(c)))
	{
		throw - 4;
	}
	FixedString<length>::Copy(c);
	return *this;
}

template<int length>
istream & DigitString<length>::Read(istream & in) //cin read
{
	char c;
	int count = 0;
	while ((c = in.get()) && !in.eof())
	{
		Chars[count++] = c;
		if (!(isdigit(c)))
		{
			throw - 5;
		}
		if (count > length)
		{
			throw - 6;
		}
	}
	Chars[count] = '\0';
	return in;
}

template<int length>
fstream & DigitString<length>::Read(fstream & in) //READ FROM THE FILE
{
	string line;
	if (in.is_open())
	{
		if (!in.eof())
		{
			getline(in, line);
			Copy(line.c_str()); //GETS EXCEPTION FROM COPY[LENGTH]
		}
	}
	else
	{
		cout << "THE FILE FAILED TO OPEN. " << endl;
	}
	return in;
}

template<int length>
fstream & DigitString<length>::Write(fstream & out) //WRITES IN FILE
{
	out << "" << Chars << "";
	return out;
}

template<int length>
ostream & DigitString<length>::Display(ostream & out) //DISPLAYS WHAT IS IN THE DIGIT STRING
{
	out << Chars << "\n";
	return out;
}

template<int length>
DigitString<length> & DigitString<length>::operator = (const DigitString <length> & c)
{
	FixedString<length>::Copy(c.Chars);
	return *this;
}

template<int length>
DigitString<length> & DigitString<length>::operator = (const char * c)
{
	if (!(isDigit(c)))
	{
		throw - 4;
	}
	FixedString<length>::Copy(c);
	return *this;
}

template<int length>
bool DigitString<length>::operator == (const DigitString <length> & c)
{
	if (Compare(c) == 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator == (const char * c)
{
	if (Compare(c) == 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator >	(const DigitString <length> & c)
{
	if (Compare(c) > 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator > (const char * c)
{
	if (Compare(c) > 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator >= (const DigitString <length> & c)
{
	if (Compare(c) >= 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator >= (const char * c)
{
	if (Compare(c) >= 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator <	(const DigitString <length> & c)
{
	if (Compare(c) < 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator <	(const char * c)
{
	if (Compare(c) < 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator <= (const DigitString <length> & c)
{
	if (Compare(c) <= 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator <= (const char * c)
{
	if (Compare(c) <= 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator != (const DigitString <length> & c)
{
	if (Compare(c) != 0)
		return true;
	else
		return false;
}

template<int length>
bool DigitString<length>::operator != (const char * c)
{
	if (Compare(c) != 0)
		return true;
	else
		return false;
}

//METHOD TO CHECK THE NUMBERS OUTSIDE OF THE CLASS (MAKE SURE TO PUT THAT INLINE)
inline bool isDigit(const char* str)
{
	int StringLength = strlen(str);
	for (int c = 0; c > StringLength; c++)
	{
		if (!(isdigit(str[c])))
		{
			return false;
		}
	}
	return true;
}

//INPUT/OUTPUT OPERATORS OUTSIDE OF THE CLASS (MAKE SURE TO PUT THAT INLINE)
template<int length>
inline ostream & operator << (ostream & out, DigitString<length> & c)
{
	return c.Display(out);
}

template<int length>
inline fstream & operator << (fstream & out, DigitString<length> & c)
{
	return c.Write(out);
}

template<int length>
inline istream & operator >> (istream & in, DigitString<length> & c)
{
	return c.Read(in);
}

template<int length>
inline fstream & operator >> (fstream & in, DigitString<length> & c)
{
	return c.Read(in);
}
#endif
