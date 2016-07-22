#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int arr[1003];

int main()
{
    int ca, sum, num;
    int counts, psb;
    int c = 1;
    cin >> ca;
    while(ca--)
    {
        psb = counts = 0;
        cin >> sum >> num;
        for(int i = 0; i < num; i++)
            cin >> arr[i];
        sort(arr, arr + num);
        for(int i = num - 1; i >= 0; i--)
        {
            sum -= arr[i];
            if(sum <= 0)
            {
                counts++;
                psb = 1;
                break;
            }
            else
                counts++;
        }
        printf("Scenario #%d:\n", c++);
        if(psb)
            cout << counts << endl;
        else
            cout << "impossible" << endl;
        cout << endl;
    }
    return 0;
}
