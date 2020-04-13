#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    string str;
    while(cin >> n >> m) {
        vector<vector<int>> cnt(m, vector<int>(5, 0));
        for(int i = 0; i < n; ++i) {
            cin >> str;
            for(int j = 0; j < m; ++j) {
                ++cnt[j][str[j] - 'A'];
            }
        }
        int score, mx;
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            cin >> score;
            mx = cnt[i][0];
            for(int j = 0; j < 5; ++j) {
                mx = max(mx, cnt[i][j]);
            }
            ans += score * mx;
        }
        cout << ans << endl;
    }
    return 0;
}