#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, L;
    while(cin >> n >> L) {
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end());
        int cur_right = 0;
        int mx_right = 0;
        int cnt = 0;
        int pos = 0;
        while(pos < n && cur_right < L) {
            while(pos < n && arr[pos].first <= cur_right) {
                mx_right = max(mx_right, arr[pos].second);
                ++pos;
            }
            if(pos < n && arr[pos].first > mx_right) {
                cnt = -1;
                break;
            }else if(pos == n) {
                if(mx_right < L) {
                    cnt = -1;
                }else {
                    ++cnt;
                }
                break;
            }else {
                ++cnt;
                cur_right = mx_right;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}