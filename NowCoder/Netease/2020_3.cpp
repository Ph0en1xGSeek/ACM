#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int arr[200002];
    memset(arr, 0, sizeof(arr));
    int n, m, tmp;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        ++arr[tmp];
    }
    for(int i = 200000-1; i >= 0; --i) {
        arr[i] += arr[i+1];
    }
    for(int i = 0; i < m; ++i) {
        cin >> tmp;
        cout << arr[tmp] << endl;
        memcpy(arr+tmp, arr+tmp+1, 200000 - tmp);
    }
    return 0;
}