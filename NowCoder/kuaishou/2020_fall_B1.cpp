#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<long long> arr(num);
    long long sum = 0;
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    long long half = sum >> 1;
    vector<long long> dp(half + 1, 0);
    for(int i = 0; i < num; ++i) {
        for(int j = half; j >= arr[i]; --j) {
            dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
        }
    }
    cout << abs(sum - dp[half] - dp[half]) << endl;
    return 0;
}