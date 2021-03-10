#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

int arr[2017];
int result[2017];

map<int , int> isExist;

int main() {

    int cnt = 0;
    int k, n;
    scanf("%d%d", &k, &n);
    scanf("%d", &arr[0]);
    isExist[arr[0]+2000] = 2;
    for(int i = 1; i < k; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
        isExist[arr[i] + 2000] = 2;
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &result[i]);
    }

    for(int i = 0; i < k; i++)
    {
        if(isExist[arr[i]+2000] == 1) continue;
        else isExist[arr[i]+2000] = 1;
        int x = result[0] - arr[i];
        bool flag = true;
        for(int j = 1; j < n; j++)
        {
            if(isExist[result[j] - x + 2000] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}