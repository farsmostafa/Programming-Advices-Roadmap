
#include <iostream>
using namespace std;


struct stInfo {
	string FirstName;
	string LastName;
	short Age;
	string Phone;
};

void ReadInfo(stInfo & Info) {
	cout << "Enter First Name : ";
	cin >> Info.FirstName;
	cout << "Enter Last Name : ";
	cin >> Info.LastName;
	cout << "Enter Age : ";
	cin >> Info.Age;
	cout << "Enter Phone : ";
	cin >> Info.Phone;
}
void PrintInfo(stInfo  Info) {
	cout << "First Name : " << Info.FirstName;
	cout << "\nLast Name : " << Info.LastName;
	cout << "\nAge : " << Info.Age;
	cout << "\nPhone : " << Info.Phone;
}




int main()
{
	stInfo Person;
	ReadInfo(Person);
	PrintInfo(Person);


	system("pause>0");
}

