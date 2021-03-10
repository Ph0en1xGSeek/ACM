#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(arr[i][j] == 'Y') {
                ++cnt;
                for(int tmp_i = i, tmp_j = j; tmp_i < n && tmp_j < m; ++tmp_i, ++tmp_j) {
                    if(arr[tmp_i][tmp_j] == 'Y') {
                        arr[tmp_i][tmp_j] = 'X';
                    }else if(arr[tmp_i][tmp_j] == 'G') {
                        arr[tmp_i][tmp_j] = 'B';
                    }else {
                        break;
                    }
                }
            }else if(arr[i][j] == 'B') {
                ++cnt;
                for(int tmp_i = i, tmp_j = j; tmp_i < n && tmp_j >= 0; ++tmp_i, --tmp_j) {
                    if(arr[tmp_i][tmp_j] == 'B') {
                        arr[tmp_i][tmp_j] = 'X';
                    }else if(arr[tmp_i][tmp_j] == 'G') {
                        arr[tmp_i][tmp_j] = 'Y';
                    }else {
                        break;
                    }
                }
            }else if(arr[i][j] == 'G') {
                ++cnt;
                for(int tmp_i = i, tmp_j = j; tmp_i < n && tmp_j < m; ++tmp_i, ++tmp_j) {
                    if(arr[tmp_i][tmp_j] == 'Y') {
                        arr[tmp_i][tmp_j] = 'X';
                    }else if(arr[tmp_i][tmp_j] == 'G') {
                        arr[tmp_i][tmp_j] = 'B';
                    }else {
                        break;
                    }
                }
                ++cnt;
                for(int tmp_i = i, tmp_j = j; tmp_i < n && tmp_j >= 0; ++tmp_i, --tmp_j) {
                    if(arr[tmp_i][tmp_j] == 'B') {
                        arr[tmp_i][tmp_j] = 'X';
                    }else if(arr[tmp_i][tmp_j] == 'G') {
                        arr[tmp_i][tmp_j] = 'Y';
                    }else {
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}