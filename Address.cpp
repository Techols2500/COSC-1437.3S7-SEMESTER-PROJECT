//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//**************************************************************************

#include "Address.h"
#include "Student.h"

Address::Address()
{
}



Address::~Address()
{
}

void Address::Read()
{
	bool	Error;
	int		x;

	cout << "Enter Street: ";
	Street.Read();
	cout << "Enter City: ";
	City.Read();
	cout << "Enter State: ";
	State.Read();

	do
	{
		Error = false;
		cout << "Enter Zip: ";
		Zip.Read();

		if (strlen(Zip) == 5)
		{
			for (x = 0; x < 5; x++)
			{
				if (isdigit(Zip[x]))
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
			cout << "Please use 5 digits" << endl;
			throw Student::SizeError;
			Error = true;
		}
	} while (Error);
}

void Address::Display()
{
	cout << "Address: ";
	Street.Display();
	cout << ", ";
	City.Display();
	cout << ", ";
	State.Display();
	cout << " ";
	Zip.Display();
	cout << endl;
}

void Address::SetFile(char * c)
{
	int			x;
	char *		pNumber;
	char		Separators[] = " ";
	WCS_String	temp[4];


	pNumber = strtok(c, Separators);
	x = 0;
	while (pNumber != NULL)
	{
		temp[x] = pNumber;
		pNumber = strtok(NULL, Separators);
		x++;
	}

	Street = temp[0];
	City = temp[1];
	State = temp[2];
	Zip = temp[3];
}

WCS_String Address::GetAddress()
{
	WCS_String Line;

	Line.Copy(Street);
	Line.Concat(" ");
	Line.Concat(City);
	Line.Concat(" ");
	Line.Concat(State);
	Line.Concat(" ");
	Line.Concat(Zip);

	return Line;
}


