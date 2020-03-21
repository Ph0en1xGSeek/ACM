#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int from, int to, long long &ans) {
    if(from >= to) {
        return;
    }
    int mid = from + ((to - from) >> 1);
    merge(arr, from, mid, ans);
    merge(arr, mid+1, to, ans);
    vector<int> tmp(to - from + 1);
    int left = from, right = mid + 1;
    int pos = 0, sum = 0;
    while(left <= mid && right <= to) {
        if(arr[left] <= arr[right]) {
            sum += arr[left];
            tmp[pos++] = arr[left];
            ++left;
        }else {
            ans += sum;
            tmp[pos++] = arr[right];
            ++right;
        }
    }
    while(left <= mid) {
        tmp[pos++] = arr[left];
        ++left;
    }
    while(right <= to) {
        tmp[pos++] = arr[right];
        ans += sum;
        ++right;
    }
    copy(tmp.begin(), tmp.end(), arr.begin() + from);
}

int main() {
    int num;
    while(cin >> num) {
        vector<int> arr(num, 0);
        for(int i = 0; i < num; ++i) {
            cin >> arr[i];
        }
        long long ans = 0;
        merge(arr, 0, num - 1, ans);
        cout << ans << endl;
    }
    return 0;
}