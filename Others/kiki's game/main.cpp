#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 2300

using namespace std;

bool arr[M][M];

int main()
{
    int n, m;
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(i == 1 && j == 1) continue;
            if((i != 1 && !arr[i-1][j]) || (j != 1 && !arr[i][j-1]) || (i != 1 && j != 1 && !arr[i-1][j-1]))
                arr[i][j] = true;
        }
    }
    while(scanf("%d%d", &n, &m) && n != 0)
    {
        if(arr[n][m])
            printf("Wonderful!\n");
        else
            printf("What a pity!\n");
    }
    return 0;
}
