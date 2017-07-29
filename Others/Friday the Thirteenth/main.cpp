#include <iostream>

using namespace std;

int main()
{
    int in13 = 6;
    int num;
    cin >> num;
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int counts[7] = {0};
    for(int i = 1900; i < 1900 + num; i++)
    {
        if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
            month[2] = 29;
        for(int j = 1; j <= 12; j++)
        {
            counts[in13]++;
            in13 += month[j];
            in13 = in13 % 7;
        }
        month[2] = 28;
    }
    cout << counts[6];
    for(int i = 0; i < 6; i++)
        cout << ' ' << counts[i];

    return 0;
}
