#include <iostream>
#include <stdio.h>

using namespace std;

long long cs[200001];

int main()
{
    long long ca, num1, num2, cnt;
    long long ave1, tmp, ave2;
    cin >> ca;
    while(ca--)
    {
        ave1 = ave2 = 0;
        cnt = 0;
        cin >> num1 >> num2;
        for(long long i = 0; i < num1; i++)
        {
            cin >> cs[i];
            ave1 += cs[i];
        }
        for(long long i = 0; i < num2; i++)
        {
            cin >> tmp;
            ave2 += tmp;
        }
        for(long long i = 0; i < num1; i++)
            if(num1*cs[i] < ave1 && num2*cs[i] > ave2)
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
