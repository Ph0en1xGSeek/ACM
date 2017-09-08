#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int num;
    int cnt;
    while(~scanf("%d", &num))
    {
        cnt = 0;
        for(int i = 2; i <= 8000000; i++)
        {
            while(num % i == 0)
            {
                cnt++;
                num /= i;
            }
            if(num == 1) break;
        }
        if(num != 1) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
