#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    if(num <= 2) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> arr(num);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 1;
    vector<unordered_map<int, int>> dp(num);

    for(int i = 1; i < num; ++i) {
        for(int j = 0; j < i; ++j) {
            int diff = arr[i] - arr[j];
            dp[i][diff] = dp[j][diff] + 1;
            ans = max(ans, dp[i][diff]);
        }
    }
    cout << ans + 1 << endl;
    return 0;
}