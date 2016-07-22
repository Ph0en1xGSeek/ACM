#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void monthTitle(int year , int month);
void monthBody(int year , int month);
int starDay(int year , int month);
int promptAndGet(string prompt);
int countTheDay(int year , int month);
bool isLeapyear(int year);
int daysA_Month(int year , int month);
void monthName(int month);


int main()
{
  int year , month;
  year = promptAndGet("year");
  month = promptAndGet("month");
  monthTitle(year , month);
  monthBody(year , month);

    system("pause");
    return 0;
}



void monthTitle(int year , int month)
{
    cout << "\n        ";
    monthName(month);
    cout << " " << year << endl;
    cout << "*******************************\n";
    cout << " Sun Mon Tue Wed Thu Fri Sat\n";
}


void monthBody(int year , int month)
{
    int startDay = starDay(year , month);
    int numberOfDay = daysA_Month(year , month);

    int i = 0;
    for (i = 0 ; i < startDay ;i++)
        cout << "    ";
    for (i = 1 ; i <= numberOfDay ; i++)
    {
        cout << setw(4) << i;
        if ((i + startDay) % 7 == 0 )//Sunday is the leftmost one
            cout << endl ;
    }
    cout << "\n*******************************\n";

}



int starDay(int year , int month)//begin with Monday (return 1), Tuesday and so on
{
    int date;
    date = (countTheDay(year , month) + 3 ) % 7;
    return date;
}




int promptAndGet(string prompt)
{
    int getIn;
    cout << "Please input " << prompt << ":  ";
    cin >> getIn;

    return getIn;
}

int countTheDay(int year , int month)
{
    int day = 0;
    for(int i = 1800 ; i < year ; i++)
    {
        if (isLeapyear(i))
        day += 366;
        else
        day += 365;
    }
    for (int i = 1 ; i < month ; i++)//To the month before
    {
        day += daysA_Month(year , i);
    }
    return day;
}

bool isLeapyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int daysA_Month(int year , int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12)
    {
        return 31;
    }
    if (month == 2)
    {
        return isLeapyear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
        return 0;//If month is incorrect

}


void monthName(int month)
{
   string monthName[12] = {"January" , "February" , "March" , "April" , "May" , "June" ,
                            "July" , "August" , "September" , "October" , "November" , "December"};

   cout << monthName[month - 1];
}







