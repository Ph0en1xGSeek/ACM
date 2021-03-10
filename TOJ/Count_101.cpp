#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[10001][4] = {{0}};
    arr[1][0] = 2;
    arr[2][0] = 4;
    arr[3][0] = arr[3][2] = arr[3][3] = 2;
    arr[3][1] = 1;
    for(int i = 4; i <= 10000; i++)
    {
        arr[i][0] = (arr[i-1][0] + arr[i-1][2]) % 9997;
        arr[i][1] = arr[i-1][0];
        arr[i][2] = (arr[i-1][1] + arr[i-1][3]) % 9997;
        arr[i][3] = (arr[i-1][1] + arr[i-1][3]) % 9997;
    }
    int num;
    while(scanf("%d", &num) && num != -1)
    {
        printf("%d\n", (arr[num][0]+arr[num][1]+arr[num][2]+arr[num][3])%9997);
    }
    return 0;
}
