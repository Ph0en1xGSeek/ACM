#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;


int main()
{
    char ch[110];
    long long tmp;
    int ans;
    while(scanf("%s", ch) != EOF)
    {
        if(strlen(ch) > 10)
        {
            printf("TAT\n");
            continue;
        }
        tmp = 0;
        ans = -1;

        for(int i = 0; i < strlen(ch); i++)
        {
            tmp = tmp*10 +(ch[i] - '0');
        }
        if(tmp==1)
            ans=0;
        else if(tmp>1&&tmp<=3)
            ans=1;
        else if(tmp>=4&&tmp<=15)
            ans=2;
        else if(tmp>=16&&tmp<=255)
            ans=3;
        else if(tmp>=256&&tmp<=65535)
            ans=4;
        else if(tmp>=65536&&tmp<=4294967295)
            ans=5;
        if(ans==-1)
            printf("TAT\n");
        else
            printf("%d\n", ans);


    }
    return 0;
}
