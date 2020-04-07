#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long merge(vector<pair<int, int>> &arr, int from, int to) {
    if(from >= to) {
        return 0;
    }
    int mid = from + ((to - from) >> 1);
    long long lsum = merge(arr, from, mid);
    long long rsum = merge(arr, mid+1, to);
    vector<pair<int, int>> tmp(to - from + 1);
    int pos1 = from, pos2 = mid + 1, pos = 0;
    long long sum = 0;
    for(int i = from; i <= mid; ++i) {
        sum += arr[i].second;
    }
    long long ret = 0;
    while(pos1 <= mid && pos2 <= to) {
        if(arr[pos1].first <= arr[pos2].first) {
            sum -= arr[pos1].second;
            tmp[pos++] = arr[pos1++];
        }else {
            ret += (long long)(mid - pos1 + 1) * arr[pos2].second - sum;
            tmp[pos++] = arr[pos2++];
        }
    }
    while(pos1 <= mid) {
        tmp[pos++] = arr[pos1++];
    }
    while(pos2 <= to) {
        tmp[pos++] = arr[pos2++];
    }
    copy(tmp.begin(), tmp.end(), arr.begin() + from);
    return lsum + rsum + ret;
} 

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    long long ans = merge(arr, 0, n-1);
    cout << ans << endl;
    return 0;
}