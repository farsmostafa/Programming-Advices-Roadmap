
#include <iostream>
using namespace std;

enum enScreenColor{Red=1,Blue=2,Green=3,Yellow=4};


int main()
{
	cout << "*********************************************\n";
	cout << "(1) Red\n";
	cout << "(2) Blue\n";
	cout << "(3) Green\n";
	cout << "(4) Yellow\n";
	cout << "*********************************************\n\n";
	cout << "Please Enter The Number of Your Color : ";
	short colorNumber;
	cin >> colorNumber;

	enScreenColor Color = (enScreenColor)colorNumber;

	switch (Color)
	{
	case Red:
		system("color 4F");
		break;
	case Blue:
		system("color 1F");
		break;
	case Green:
		system("color 2F");
		break;
	case Yellow:
		system("color 6F");
		break;
	default:
		system("color 4F");
		break;
	}


	system("pause>0");
}

