#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int arr[3][10] = {0,9,8,7,6,5,4,3,2,1,
                   0,3,6,9,2,5,8,1,4,7,
                    0,7,4,1,8,5,2,9,6,3};

int main()
{
    int ca, t, num, tot, pos1, pos2;
    char str[10];
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        scanf("%s", str);
        tot = 0;
        for(int j = strlen(str)-1, t = 0; j >= 0; j--, t++)
        {
            if(str[j] == '?')
            {
                pos1 = j;
                pos2 = t;
                continue;
            }
            num = str[j] - '0';
            tot += arr[t%3][num];
        }
        tot = (10 - tot%10)%10;
        for(int j = 0; j < 10; j++)
            if(arr[pos2%3][j] == tot)
                str[pos1] = j + '0';
        printf("Scenario #%d:\n%s\n\n", i, str);

    }
    return 0;
}
