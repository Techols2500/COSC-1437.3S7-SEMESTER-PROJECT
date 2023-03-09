//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 

#include "Name.h" 


Name::Name()
{

}

Name::~Name()
{

}

void Name::Read()
{
	cout << "Enter First Name: ";
	First.Read();
	if (First == "EOF")
		throw First;
	cout << "Enter Middile Name: ";
	Middle.Read();
	cout << "Enter Last Name: ";
	Last.Read();
}

void Name::Display()
{
	cout << "Name: ";
	First.Display();
	cout << " ";
	Middle.Display();
	cout << " ";
	Last.Display();
	cout << endl;
}

void Name::SetFile(char * c)
{
	int			x;
	char *		pNumber;
	char		Separators[] = " ";
	WCS_String	temp[3];


	pNumber = strtok(c, Separators);
	x = 0;
	while (pNumber != NULL)
	{
		temp[x] = pNumber;
		pNumber = strtok(NULL, Separators);
		x++;
	}

	First = temp[0];
	Middle = temp[1];
	Last = temp[2];
}

WCS_String Name::GetName()
{
	WCS_String Line;

	Line.Copy(First);
	Line.Concat(" ");
	Line.Concat(Middle);
	Line.Concat(" ");
	Line.Concat(Last);
	return Line;
}

int Name::CompareName(const Name & N) const
{
	int Result;

	if ((Result = Last.Compare(N.Last)) == 0)
		if ((Result = First.Compare(N.First)) == 0)
			if ((Result = Middle.Compare(N.Middle)) == 0)
				return Result;
}