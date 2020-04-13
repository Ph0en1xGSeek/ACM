#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> arr(num);
    int sum = 0;
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    int half = (sum >> 1);
    vector<int> dp(half+1, 0);
    for(int i = 0; i < num; ++i) {
        for(int j = half; j >= arr[i]; --j) {
            dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
        }
    }
    cout << sum - dp[half] - dp[half] << endl;
    return 0;
}