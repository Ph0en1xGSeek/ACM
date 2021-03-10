#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int mod = 1000000007;
    int k;
    cin >> k;
    int A, X, B, Y;
    cin >> A >> X >> B >> Y;
    int size = max(X, Y);
    vector<vector<int>> c(size + 1, vector<int>(size + 1, 0));
    c[0][0] = 1;
    for(int i = 1; i < size + 1; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
        }
    }
    int ans = 0;
    for(int i = 0; i <= X; ++i) {
        int tmp = k - (i * A);
        if(tmp < 0) {
            break;
        }
        if(tmp % B == 0 && tmp / B <= Y) {
            ans = (ans + ((long long)c[X][i] * (long long)c[Y][tmp / B]) % mod) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}