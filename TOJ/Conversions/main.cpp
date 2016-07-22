#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
    int num;
    cin >> num;
    string str;
    double n;
    for(int i = 1; i <= num; i++)
    {
        cin >> n >> str;
        if(str == "kg")
            cout << i << ' ' << setprecision(4) << fixed << 2.2046 * n << " lb" << endl;
        else if(str == "lb")
            cout << i << ' ' << setprecision(4) << fixed << 0.4536 * n << " kg" << endl;
        else if(str == "l")
            cout << i << ' ' << setprecision(4) << fixed << 0.2642 * n << " g" << endl;
        else
            cout << i << ' ' << setprecision(4) << fixed << 3.7854 * n << " l" << endl;
    }
    return 0;
}
