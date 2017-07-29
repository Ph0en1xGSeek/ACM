#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#define pi acos(-1)

using namespace std;

char str[1000010];
double arr[150010];


int main()
{
    arr[1] = 1.0;
    for(int i = 2; i <= 150000; i++)
        arr[i] = arr[i-1] + (double)(1.0/i)*(double)(1.0/i);

    while(~scanf("%s", &str))
    {
        int len = strlen(str);
        if(len > 6)
        {
            printf("1.64493\n");
        }
        else
        {
            int pos = 0;
            for(int i = 0; i < len; i++)
                pos = pos * 10 + (str[i]-'0');
            if(pos > 150000)
                printf("1.64493\n");
            else
                printf("%.5lf\n", arr[pos]);
        }
    }
    return 0;
}
