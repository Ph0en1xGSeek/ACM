#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int cur = -1;
    int cnt = 1;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        if(cur != arr[i]) {
            if(cnt == 1) {
                cur = arr[i];
            }else {
                --cnt;
            }
        }else {
            ++cnt;
        }
    }
    cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] == cur) {
            ++cnt;
        }
    }
    if(cnt > n / 2) {
        cout << cur << endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}