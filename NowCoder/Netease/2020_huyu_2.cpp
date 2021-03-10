#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

void preprocess(vector<pair<int, int>> &arr, vector<int> &memo, int n) {
    vector<bool> sink(n, false);
    memo[0] = 1;
    int cnt = 1;
    for(int i = 1; i <= n; ++i) {
        if((arr[i-1].second == 0 || sink[arr[i-1].second - 1]) && (arr[i-1].second == n-1 || sink[arr[i-1].second + 1])) {
            --cnt;
        }else if((arr[i-1].second == 0 || sink[arr[i-1].second - 1]) || (arr[i-1].second == n-1 || sink[arr[i-1].second + 1])) {
            
        }else {
            ++cnt;
        }
        sink[arr[i-1].second] = true;
        memo[i] = cnt;
    }
}

int main() {
    int n, q, tmp;
    cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> memo(n+1, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    preprocess(arr, memo, n);
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> tmp;
        int left = 0, right = n-1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(arr[mid].first <= tmp) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        cout << memo[left] << endl;
    }
    return 0;
}