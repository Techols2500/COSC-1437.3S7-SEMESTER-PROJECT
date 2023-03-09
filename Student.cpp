//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 


#include "Student.h" 

Student::Student()
{

}

Student::~Student()
{

}

void Student::Read()
{
	bool	Error;
	bool	Error2;
	int		x;


	do
	{
		Error2 = false;
		try
		{
			Name.Read();

			do
			{
				Error = false;
				cout << "Enter ID: ";
				ID.Read();

				if (strlen(ID) == 9)
				{
					for (x = 0; x < 9; x++)
					{
						if (isdigit(ID[x]))
							cout;
						else
						{
							cout << "Please use numbers only" << endl;
							throw NumError;
							Error = true;
							break;
						}
					}
				}
				else
				{
					cout << "Please use 9 digits" << endl;
					throw SizeError;
					Error = true;
				}
			} while (Error);

			Address.Read();
			Number.Read();
		}
		catch (Student::ErrorCodes e)
		{
			switch (e)
			{
			case Student::End:
				throw e;
				break;
			case Student::NumError:
				cout << " Digit Error" << endl;
				Error2 = true;
				break;
			case Student::SizeError:
				cout << "Size Error" << endl;
				Error2 = true;
				break;
			default:		cout << "Error 102" << endl;
			}
		}
	} while (Error2);
}

void Student::Display()
{
	Name.Display();
	cout << "ID: ";
	ID.Display();
	cout << endl;
	Address.Display();
	Number.Display();
}

void Student::SetName(char * c)
{
	Name.SetFile(c);
}

void Student::SetID(char * c)
{
	ID = c;
}

void Student::SetAddress(char * c)
{
	Address.SetFile(c);
}

void Student::SetNumber(char * c)
{
	Number.SetFile(c);
}

WCS_String Student::GetID()
{
	return ID;
}

WCS_String Student::GetName()
{
	return Name.GetName();
}

WCS_String Student::GetAddress()
{
	return Address.GetAddress();
}

WCS_String Student::GetNumber()
{
	return Number.GetNumber();
}

int Student::CompareName(const Student & N) const
{
	return Name.CompareName(N.Name);
}

int Student::CompareID(const Student & N) const
{
	return ID.Compare(N.ID);
}

Student & Student::Copy(const Student & N)
{
	return operator = (N);
}


int ReadFile(Student S[])
{
	fstream MyFile;
	char	Line[81];
	int		x = 0;
	int		y = 0;

	MyFile.open("Student Information.txt", ios_base::in);
	while (!MyFile.is_open())
	{
		MyFile.clear();
		MyFile.open("Student Information.txt", ios_base::in);
	}

	do
	{
		MyFile.getline(Line, 81);
		switch (x % 5)
		{
		case 0: S[y].SetName(Line);
			break;
		case 1: S[y].SetID(Line);
			break;
		case 2: S[y].SetAddress(Line);
			break;
		case 3: S[y].SetNumber(Line);
			break;
		case 4: y++;
			break;
		default:cout << "Error 100" << endl;
			system("pause");
		}
		x++;
	} while (strcmp(Line, "EOF") != 0);

	MyFile.close();

	return y;
}

void SortName(Student S[], int i)
{
	Student temp;
	int		x;
	bool	Sorted;

	do
	{
		Sorted = true;
		for (x = 0; x + 1 < i; x++)
		{
			if (S[x].CompareName(S[x + 1]) < 0)
				cout;
			else
			{
				temp.Copy(S[x]);
				S[x].Copy(S[x + 1]);
				S[x + 1].Copy(temp);
				Sorted = false;
			}
		}

	} while (!Sorted);
	cout << "\t\tSorted by name" << endl;
}

void SortID(Student S[], int i)
{
	Student temp;
	int		x;
	bool	Sorted;

	do
	{
		Sorted = true;
		for (x = 0; x + 1 < i; x++)
		{
			if (S[x].CompareID(S[x + 1]) < 0)
				cout;
			else
			{
				temp.Copy(S[x]);
				S[x].Copy(S[x + 1]);
				S[x + 1].Copy(temp);
				Sorted = false;
			}
		}

	} while (!Sorted);
	cout << "\t\tSorted by ID" << endl;
}

void GetName(Student S[], int i)
{
	fstream		 MyFile;
	WCS_String	Line;
	int		x;

	MyFile.open("Student Information.txt", ios_base::out);
	while (!MyFile.is_open())
	{
		MyFile.clear();
		MyFile.open("Student Information.txt", ios_base::out);
	}

	for (x = 0; x < i; x++)
	{
		Line = S[x].GetName();
		MyFile << Line << endl;
		Line = S[x].GetID();
		MyFile << Line << endl;
		Line = S[x].GetAddress();
		MyFile << Line << endl;
		Line = S[x].GetNumber();
		MyFile << Line << endl;
		Line = "";
		MyFile << Line << endl;
	}

	MyFile << "EOF";

	MyFile.close();
}