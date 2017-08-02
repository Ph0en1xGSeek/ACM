#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[55][55];

int main() {

    int num;
    bool flag;
    bool tmpFlag;
    while (scanf("%d", &num) != EOF)
    {
        flag = true;
        for(int i = 0; i < num; i++)
        {
            for(int j = 0; j < num; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        for(int i = 0; i < num && flag; i++)
        {
            for(int j = 0; j < num; j++)
            {
                if(arr[i][j] < 2) continue;
                tmpFlag = false;
                for(int n = 0; n < num && !tmpFlag; n++)
                {
                    for(int m = 0; m < num; m++)
                    {
                        if(n != i && m != j)
                        {
                            if(arr[n][j] + arr[i][m] == arr[i][j])
                            {
                                tmpFlag = true;
                                break;
                            }
                        }
                    }
                }
                if(!tmpFlag)
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)    printf("Yes\n");
        else    printf("No\n");

    }
    return 0;
}