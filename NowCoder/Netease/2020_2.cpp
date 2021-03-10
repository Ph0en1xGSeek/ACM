#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ca, n, m, k, c, d, x, y;
    cin >> ca;
    while(ca--) {
        cin >> n >> m >> k;
        vector<vector<int>> arr(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < k; ++i) {
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                arr[i][j] = arr[i-1][j] + arr[i][j-1] + arr[i][j] - arr[i-1][j-1];
            }
        }
        cin >> c >> d;
        bool flag = false;
        for(int i = c; i <= n && !flag; ++i) {
            for(int j = d; j <= m; ++j) {
                if(arr[i][j] - arr[i-c][j] - arr[i][j-d] + arr[i-c][j-d] == 0) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}