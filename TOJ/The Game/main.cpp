#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int arr[25][25];
int step[4][2] = {1,0,0,1,1,1,-1,1};
bool iswin;

bool f(int x, int y, int n)
{
    if(arr[x][y] == 0)
        return false;
    for(int i = 1; i <= 4; i++)
        if(arr[x + i*step[n][0]][y + i*step[n][1]] != arr[x][y])
            return false;
    if(arr[x - step[n][0]][y - step[n][1]] == arr[x][y])
        return false;
    if(arr[x + 5*step[n][0]][y + 5*step[n][1]] == arr[x][y])
        return false;
    return true;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        iswin = 0;
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= 19; i++)
            for(int j =1; j <= 19; j++)
                scanf("%d", &arr[i][j]);

        for(int j = 1; j <= 19; j++)
        {
            for(int i = 1; i <= 19; i++)
            {
                for(int k = 0; k < 4; k++)
                {
                    if(f(i, j, k))
                    {
                        printf("%d\n", arr[i][j]);
                        printf("%d %d\n", i, j);
                        iswin = 1;
                        goto end;
                    }
                }
            }
        }
        end:;
        if(!iswin)
            printf("0\n");
    }
    return 0;
}
