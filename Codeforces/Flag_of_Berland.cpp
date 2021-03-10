#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str[105][105];
int R, G, B;

int main()
{
    int n, m;
    bool flag;
    bool state;
    while(~scanf("%d%d", &n, &m))
    {
        flag = true;
        state = false;
        R = G = B = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str[i]);
            for(int j = 0; j < m; j++)
            {
                if(str[i][j] == 'R') R++;
                else if(str[i][j] == 'G') G++;
                else B++;
            }
        }
        if(R != G || G != B) flag = false;
        else
        {
            if(n % 3 == 0)
            {
                for(int k = 1; k <= 3 && state == false; k++)
                {
                    char tmp = str[(k-1)*(n/3)][0];
                    for(int i = (k-1)*(n/3); i < k*(n/3) && state == false; i++)
                    {
                        for(int j = 0; j < m; j++)
                            if(str[i][j] != tmp)
                            {
                                state = true;
                                break;
                            }
                    }
                }
            }
            else
                state = true;

            if(state == true)
            {
                if(m % 3 == 0)
                {
                    for(int k = 1; k <= 3 && flag == true; k++)
                    {
                        char tmp = str[0][(k-1)*(m/3)];
                        for(int i = (k-1)*(m/3); i < k*(m/3) && flag == true; i++)
                        {
                            for(int j = 0; j < n; j++)
                                if(str[j][i] != tmp)
                                {
                                    flag = false;
                                    break;
                                }
                        }
                    }
                }
                else
                    flag = false;
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
