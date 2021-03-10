#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>


using namespace std;
char arr[15][15];

int findL(int x, int y)
{
    int cnt = 0;
    int i = x-1;
    while(arr[i][y] == 'X')
    {
        cnt++;
        i--;
    }
    return cnt;
}

int findR(int x, int y)
{
    int cnt = 0;
    int i = x+1;
    while(arr[i][y] == 'X')
    {
        cnt++;
        i++;
    }
    return cnt;
}

int findU(int x, int y)
{
    int cnt = 0;
    int i = y-1;
    while(arr[x][i] == 'X')
    {
        cnt++;
        i--;
    }
    return cnt;
}


int findD(int x, int y)
{
    int cnt = 0;
    int i = y+1;
    while(arr[x][i] == 'X')
    {
        cnt++;
        i++;
    }
    return cnt;
}

int findLU(int x, int y)
{
    int cnt = 0;
    int i = x-1;
    int j = y-1;
    while(arr[i][j] == 'X')
    {
        cnt++;
        i--;
        j--;
    }
    return cnt;
}

int findRD(int x, int y)
{
    int cnt = 0;
    int i = x+1;
    int j = y+1;
    while(arr[i][j] == 'X')
    {
        cnt++;
        i++;
        j++;
    }
    return cnt;
}

int findLD(int x, int y)
{
    int cnt = 0;
    int i = x-1;
    int j = y+1;
    while(arr[i][j] == 'X')
    {
        cnt++;
        i--;
        j++;
    }
    return cnt;
}

int findRU(int x, int y)
{
    int cnt = 0;
    int i = x+1;
    int j = y-1;
    while(arr[i][j] == 'X')
    {
        cnt++;
        i++;
        j--;
    }
    return cnt;
}


int main() {
    bool flag = false;
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= 10; i++)
    {
        scanf("%s", &arr[i][1]);
    }
    for(int i = 1; i <= 10 && flag == false; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if(arr[i][j] == '.')
            {
                int a = findL(i, j);
                int b = findR(i, j);
                if(a + b >= 4)
                {
                    flag = true;
                    break;
                }

                a = findU(i, j);
                b = findD(i, j);
                if(a + b >= 4)
                {
                    flag = true;
                    break;
                }

                a = findLU(i, j);
                b = findRD(i, j);
                if(a + b >= 4)
                {
                    flag = true;
                    break;
                }

                a = findLD(i, j);
                b = findRU(i, j);
                if(a + b >= 4)
                {
                    flag = true;
                    break;
                }
            }
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}