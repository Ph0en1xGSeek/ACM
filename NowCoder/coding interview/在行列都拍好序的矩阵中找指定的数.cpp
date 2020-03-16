#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    while(cin >> n >> m >> k) {
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> arr[i][j];
            }
        }
        int x = 0, y = m-1;
        while(x < n && y >= 0 && arr[x][y] != k) {
            if(arr[x][y] > k) {
                --y;
            }else {
                ++x;
            }
        }
        if(x < n && y >= 0) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
    return 0;
}