#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int dp1[1005][1005];
int dp3[1005][1005];
int dp4[1005][1005];

void init()
{
    for(int i = 0; i <= 1000; i++)
    {
        dp1[i][1001] = dp1[1001][i] = 1;
        dp3[i][1000] = dp3[1000][i] = 3;
        dp3[i][1001] = dp3[1001][i] = 1;
        dp4[i][i] = dp4[i][1000] = dp4[1000][i] = 1;
        dp4[i][1001] = dp4[1001][i] = 1;
    }
    dp3[1000][1000] = 0;
    dp3[999][999] = 3;
    dp1[1000][1000] = dp4[1000][1000] = 0;
    dp1[1001][1001] = dp4[1001][1001] = 1;

    for(int i = 1000; i >= 0; i--)
    {
        for(int j = 1000; j >= 0; j--)
        {
            if(dp1[i+1][j] == 1 && (dp1[i][j+1] == 1 && dp1[i+1][j+1] == 1))
                dp1[i][j] = 0;
            else
                dp1[i][j] = 1;
        }
    }

    for(int i = 999; i >= 0; i--)
    {
        for(int j = 999; j >= 0; j--)
        {
            if(i == 999 && j == 999){}
            else if((i == 999 || dp3[i+2][j+1] == 1) && (j == 999 || dp3[i+1][j+2] == 1))
                dp3[i][j] = 0;
            else if(dp3[i+2][j+1] == 0 || dp3[i+1][j+2] == 0)
                dp3[i][j] = 1;
            else
                dp3[i][j] = 3;


            if(dp4[i][j]) continue;
            if(!dp4[i][j])
            {
                for(int ii = i - 1; ii >= 0; ii--)
                    dp4[ii][j] = 1;
                for(int ii = j - 1; ii >= 0; ii--)
                    dp4[i][ii] = 1;
                for(int ii = 1; i-ii >= 0 && j-ii >= 0; ii++)
                    dp4[i-ii][j-ii] = 1;
            }
        }
    }


}

int main()
{
    int ca;
    int t, n, m;
    memset(dp1, 0, sizeof(dp1));
    memset(dp3, 0, sizeof(dp3));
    memset(dp4, 0, sizeof(dp4));
    init();
    scanf("%d", &ca);
    while(ca--)
    {

        scanf("%d%d%d", &t, &n, &m);
        if(t == 1)
        {
            if(dp1[1000-n+1][1000-m+1])
                printf("B\n");
            else
                printf("G\n");
        }
        else if(t == 2)
        {
            if((n-1) ^ (m-1))
                printf("B\n");
            else
                printf("G\n");
        }
        else if(t == 3)
        {
            if(dp3[1000-n+1][1000-m+1] == 1)
                printf("B\n");
            else if(dp3[1000-n+1][1000-m+1] == 0)
                printf("G\n");
            else if(dp3[1000-n+1][1000-m+1] == 3)
                printf("D\n");

        }
        else
        {
            if(dp4[1000-n+1][1000-m+1] == 1)
                printf("B\n");
            else
                printf("G\n");
        }
    }
    return 0;
}
