#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

long long arr[100010];
long long cha[100010];

int main()
{
    int ca, num;
    long long mx, secondMx, thirdMx;
    long long tot;
    scanf("%d", &ca);
    while(ca--)
    {
        tot = 0;
        scanf("%d", &num);
        scanf("%I64d", &arr[0]);
        for(int i = 1; i < num; i++)
        {
            scanf("%I64d", &arr[i]);
            cha[i-1] = abs(arr[i] - arr[i-1]);
        }
        sort(cha, cha+num-1);
        mx = cha[num-2];
        secondMx = cha[num-3];
        if(num > 3)
            thirdMx = cha[num-4];
        for(int i = 1; i < num-1; i++)
        {
            if((arr[i+1] > arr[i] && arr[i-1] > arr[i]) || (arr[i+1] < arr[i] && arr[i-1] < arr[i]))
            {
                if(num == 3)
                    tot += abs(arr[i+1] - arr[i-1]);
                else if((abs(arr[i+1] - arr[i]) == mx && abs(arr[i-1] - arr[i]) == secondMx) || (abs(arr[i+1] - arr[i]) == secondMx && abs(arr[i-1] - arr[i]) == mx))
                    tot += max(thirdMx, abs(arr[i+1] - arr[i-1]));
                else if((abs(arr[i+1] - arr[i]) == mx || abs(arr[i-1] - arr[i]) == mx))
                    tot += max(secondMx, abs(arr[i+1] - arr[i-1]));
                else
                    tot += mx;
            }
            else
            {
                if(abs(arr[i+1] - arr[i-1]) > mx)
                    tot += abs(arr[i+1] - arr[i-1]);
                else
                    tot += mx;
            }

        }
        if(abs(arr[1] - arr[0]) == mx)
            tot += secondMx;
        else
            tot += mx;
        if(abs(arr[num-1] - arr[num-2]) == mx)
            tot += secondMx;
        else
            tot += mx;
        printf("%I64d\n", tot);
    }
    return 0;
}
