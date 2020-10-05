#include <iostream>

using namespace std;

struct Date
{
    int year , month , day;
};

int main()
{
    cout << "Hello world!" << endl;

    int line;
    cin >> line;
    Date* date = new Date[line];
    for(int i = 0 ; i < line ; i++)
    {
        cin >> date[i].year >> date[i].month >> date[i].day;
    }

    for(int i = 0 ; i < line ; i++)
    {
        if((date[i].month + date[i].day) % 2 == 0 || (date[i].day == 30 && (date[i].month == 9 || date[i].month == 11)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
