#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dir[3][2] = {0,1,1,0,1,1};
int ca, m, n;
string str;

bool check(vector<string> &arr, int x, int y, int d) {
    int str_size = str.size();
    for(int i = 0; i < str_size; ++i) {
        if(arr[x][y] != str[i]) {
            return false;
        }
        x += dir[d][0];
        y += dir[d][1];
    }
    return true;
}

int main() {
    cin >> ca;
    while(ca--) {
        cin >> m >> n;
        vector<string> arr(m);
        for(int i = 0; i < m; ++i) {
            cin >> arr[i];
        }
        cin >> str;
        int str_size = str.size();
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(arr[i][j] == str[0]) {
                    for(int d = 0; d < 3; ++d) {
                        if(((d + 1) & 1) != 0 && j + str_size > n) {
                            continue;
                        }
                        if(((d + 1) & 2) != 0 && i + str_size > m) {
                            continue;
                        }
                        if(check(arr, i, j, d)) {
                            ++ans;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}