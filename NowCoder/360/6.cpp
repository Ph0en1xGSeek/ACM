#include <iostream>
#include <stdio.h>
#include <vector>
 
using namespace std;
 
 
long long get(int index, int length, vector<vector<long long>> &cnt, vector<vector<int>> &arr) {
    if(cnt[index][length] >= 0) {
        return cnt[index][length];
    }
    if(length == 0) {
        return cnt[index][length] = 1;
    }
    if(length == 1) {
        return cnt[index][length] = (long long)arr[index].size();
    }
    int size = arr[index].size();
    long long ans = 0;
    for(int i = 0; i < size; ++i) {
        ans += get(arr[index][i], length-1, cnt, arr);
    }
    return cnt[index][length] = ans;
}
 
int main() {
    int n, m;
    long long k;
    int from, to;
    cin >> n >> m >> k;
    vector<vector<long long>> cnt(n, vector<long long>(2000, -1));
    vector<vector<int>> arr(n);
    for(int i = 0; i < m; ++i) {
        cin >> from >> to;
        if((from == 0 && to == 1) || (from == 1 && to == 0)) {
            continue;
        }
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    int ans = 0;
    while(k > 0) {
        ++ans;
        for(int i = 0; i <= ans - 1; ++i) {
            k -= (get(0, i, cnt, arr) * get(1, ans - 1 - i, cnt, arr));
        }
    }
    cout << ans << endl;
    return 0;
}