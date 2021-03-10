#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int main() {
    int n, m;
    char op;
    int x, y;
    while(cin >> n >> m) {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for(int i = 0; i < m; ++i) {
            cin >> op >> x >> y;
            if(op == 'Q') {
                if(x > y) {
                    swap(x, y);
                }
                int mx = -100000;
                for(int i = x-1; i < y; ++i) {
                    mx = max(mx, arr[i]);
                }
                cout << mx << endl;
            }else {
                arr[x-1] = y;
            }
        }
    }
    return 0;
}