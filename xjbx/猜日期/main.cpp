#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{

    int date = 0;
    char answer;

    cout << "���������Ƿ�������������ڣ�" << endl;
    cout << "1  3  5  7\n9  11 13 15\n17 19 21 23\n25 27 29 31" << endl;
    cout << "�����������y��Y: ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y'){
        date += 1;
    }


    cout << "\n���������Ƿ�������������ڣ�" << endl;
    cout << "2  3  6  7\n10 11 14 15\n18 19 22 23\n26 27 30 31" << endl;
    cout << "�����������y��Y: ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y'){
        date += 2;
    }


    cout << "\n���������Ƿ�������������ڣ�" << endl;
    cout << "4  5  6  7\n12 13 14 15\n20 21 22 23\n28 29 30 31" << endl;
    cout << "�����������y��Y: ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y'){
        date += 4;
    }


    cout << "\n���������Ƿ�������������ڣ�" << endl;
    cout << "8  9  10 11\n12 13 14 15\n24 25 26 27\n28 29 30 31" << endl;
    cout << "�����������y��Y: ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y'){
        date += 8;
    }


    cout << "\n���������Ƿ�������������ڣ�" << endl;
    cout << "16 17 18 19\n20 21 22 23\n24 25 26 27\n28 29 30 31" << endl;
    cout << "�����������y��Y: ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y'){
        date += 16;
    }

    cout << "\n\n�����������Ϊ:  " << date << "��" << endl;


    system("pause");
    return 0;
}
