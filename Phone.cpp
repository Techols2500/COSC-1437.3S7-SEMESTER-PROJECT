//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 


#include "Phone.h"
#include "Student.h"

Phone::Phone()
{

}

Phone::~Phone()
{

}

void Phone::Read()
{
	bool	Error;
	int		x;

	do
	{
		Error = false;
		cout << "Enter Area Code: ";
		Area.Read();

		if (strlen(Area) == 3)
		{
			for (x = 0; x < 3; x++)
			{
				if (isdigit(Area[x]))
					cout;
				else
				{
					cout << "Please use numbers only" << endl;
					throw Student::NumError;
					Error = true;
					break;
				}
			}
		}
		else
		{
			cout << "Please use 3 digits" << endl;
			throw Student::SizeError;
			Error = true;
		}
	} while (Error);

	do
	{
		Error = false;
		cout << "Enter Phone Number: ";
		Number.Read();

		if (strlen(Number) == 6)
		{
			for (x = 0; x < 6; x++)
			{
				if (isdigit(Number[x]))
					cout;
				else
				{
					cout << "Please use numbers only" << endl;
					throw Student::NumError;
					Error = true;
					break;
				}
			}
		}
		else
		{
			cout << "Please use 6 digits" << endl;
			throw Student::SizeError;
			Error = true;
		}
	} while (Error);
}

void Phone::Display()
{
	cout << "Phone Number: " << Area << Number << endl;
}

void Phone::SetFile(char * c)
{
	int			x;
	char *		pNumber;
	char		Separators[] = " ";
	WCS_String	temp[2];


	pNumber = strtok(c, Separators);
	x = 0;
	while (pNumber != NULL)
	{
		temp[x] = pNumber;
		pNumber = strtok(NULL, Separators);
		x++;
	}

	Area = temp[0];
	Number = temp[1];
}


WCS_String Phone::GetNumber()
{
	WCS_String Line;

	Line.Copy(Area);
	Line.Concat(" ");
	Line.Concat(Number);

	return Line;
}
