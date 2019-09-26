#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dfs(vector<int> &arr, int pos, long long sum, long long weight) {
    if(pos == arr.size()-1) {
        if(arr[pos] <= weight)
            return 2;
        else
            return 1;
    }
    if(sum <= weight) {
        return (1 << (arr.size() - pos));
    }
    if(arr[pos] > weight) {
        return 1;
    }
    return dfs(arr, pos+1, sum - arr[pos], weight) + dfs(arr, pos+1, sum - arr[pos], weight - arr[pos]);
}

int main() {
    int n;
    long long w;
    scanf("%d%lld", &n, &w);
    vector<int> arr(n);
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = dfs(arr, 0, sum, w);
    printf("%d\n", ans);
    return 0;
}