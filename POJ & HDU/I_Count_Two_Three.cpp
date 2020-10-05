#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>

using namespace std;

int a[4] = {2,3,5,7};
long long arr[1000000];
queue<long long> q;
map<long long, bool> mp;
int num;

void init()
{
    num = 0;
    q.push(1);
    while(!q.empty())
    {
        long long tmp = q.front();
        q.pop();
        arr[num++] = tmp;
        for(int i = 0; i <4; i++)
        {
            if(tmp * a[i] <= 1100000000 && mp[tmp*a[i]] == false)
            {
                mp[tmp*a[i]] = true;
                q.push(tmp*a[i]);
            }
        }
    }
    sort(arr, arr+num);
}

int main()
{
    init();
    int ca;
    long long n;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%I64d", &n);
        int pos = lower_bound(arr, arr+num, n) - arr;
        printf("%I64d\n", arr[pos]);
    }
    return 0;
}
