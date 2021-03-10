#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> arr(num), leftMax(num), rightMax(num);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    leftMax[0] = arr[0];
    for(int i = 1; i < num; ++i) {
        leftMax[i] = max(leftMax[i-1], arr[i]);
    }
    rightMax[num-1] = arr[num-1];
    for(int i = num-1; i >= 0; --i) {
        rightMax[i] = max(rightMax[i+1], arr[i]);
    }
    int ans = -1;
    for(int i = 0; i < num-1; ++i) {
        ans = max(ans, abs(rightMax[i+1] - leftMax[i]));
    }
    cout << ans << endl;
    return 0;
}