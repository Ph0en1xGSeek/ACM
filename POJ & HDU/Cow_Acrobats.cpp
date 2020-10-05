#include <iostream>
#include <algorithm>
#define INF  1 << 29

using namespace std;

struct cow
{
    int w;
    int s;
}arr[50001];

bool cmp(cow a, cow b)
{
    return (a.s+a.w) < (b.s+b.w);
}

int main()
{
    int num;
    long long sum = 0;
    long long ans = -INF;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i].w >> arr[i].s;
        sum += arr[i].w;
    }
    sort(arr, arr + num, cmp);
    for(int i = num - 1; i >= 0; i--)
    {
        sum -= arr[i].w;//用于表示牛承受的压力
        ans = (ans > sum - arr[i].s)? ans:sum - arr[i].s;
    }
    cout << ans << endl;
    return 0;
}
