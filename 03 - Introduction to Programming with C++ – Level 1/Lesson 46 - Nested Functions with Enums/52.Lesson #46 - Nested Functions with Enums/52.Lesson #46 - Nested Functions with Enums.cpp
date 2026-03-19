#include <iostream>
using namespace std;


enum enWeekDay { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7 };

void ShowWeekDaysMenu(){
    cout << "*************************************\n";
    cout << "Week Days";
    cout << "*************************************\n";
    cout << "1: Sunday\n";
    cout << "2: Monday\n";
    cout << "3: Tuesday\n";
    cout << "4: Wednesday\n";
    cout << "5: Thursday\n";
    cout << "6: Friday\n";
    cout << "7: Saturday\n";
    cout << "*************************************\n";
    cout << "Enter The Number Of Day : ";
}

enWeekDay ReadWeekDay() {
    short weekDay = 0; 
    cin >> weekDay;
    return (enWeekDay)weekDay;
}



string GetWeekDayName(enWeekDay WeekDay) {
    switch (WeekDay)
    {
    case Sun:
        return "Sunday";
        break;
    case Mon:
        return "Monday";
        break;
    case Tue:
        return "Tuesday";
        break;
    case Wed:
        return "Wednesday";
        break;
    case Thu:
        return "Thursday";
        break;
    case Fri:
        return "Friday";
        break;
    case Sat:
        return "Saturday";
        break;
    default:
        break;
    }
}

int main()
{
    ShowWeekDaysMenu();
    cout << "Today is : " << GetWeekDayName(ReadWeekDay());
    
    system("pause>0");
}

