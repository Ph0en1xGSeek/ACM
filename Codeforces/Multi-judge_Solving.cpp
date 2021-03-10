#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


long long arr[1002];

int main() {

    int n;
    long long k;
    int cnt = 0;
    scanf("%d%I64d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", &arr[i]);
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++)
    {
        while(2 * k < arr[i])
        {
            k *= 2;
            cnt++;
        }
        k = max(k, arr[i]);
    }
    printf("%d\n", cnt);
    return 0;
}