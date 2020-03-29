#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, vector<long long> &all, int depth, int from, int to) {
    if(from == to) {
        return;
    }
    int mid = from + ((to - from) >> 1);
    merge(arr, all, depth-1, from, mid);
    merge(arr, all, depth-1, mid+1, to);
    int pos1 = from, pos2 = mid + 1, pos = 0;
    vector<int> tmp(to - from + 1);
    while(pos1 <= mid && pos2 <= to) {
        if(arr[pos1] <= arr[pos2]) {
            tmp[pos++] = arr[pos1++];
        }else {
            all[depth] += mid + 1 - pos1;
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
}

int main() {
    int n, m, layer;
    while(cin >> n) {
        vector<long long> rev_all(n, 0);
        vector<long long> all(n, 0);
        vector<int> arr((1 << n));
        for(int i = 0; i < (1 << n); ++i) {
            cin >> arr[i];
        }
        vector<int> rev((1 << n));
        rev.assign(arr.rbegin(), arr.rend());
        merge(arr, all, n-1, 0, (1 << n) - 1);
        merge(rev, rev_all, n-1, 0, (1 << n) - 1);
        cin >> m;
        for(int i = 0; i < m; ++i) {
            cin >> layer;
            for(int j = 0; j < layer; ++j) {
                swap(all[j], rev_all[j]);
            }
            long long ans = 0;
            for(int j = 0; j < n; ++j) {
                ans += all[j];
            }
            cout << ans << endl;
        }
    }
    return 0;
 }