#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    bool flag = true;
    cin >> n >> k;
    vector<int> dp(k + 1, 0);
    int i;
    for(i = 0; flag; ++i) {
        for(int j = k; j > 0; --j) {
            dp[j] = dp[j] + dp[j-1] + 1;
            if(dp[j] >= n) {
                flag = false;
                break;
            }
        }
    }
    cout << i << endl;
    return 0;
}