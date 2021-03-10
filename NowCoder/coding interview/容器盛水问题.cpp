#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    int tmp = -1;
    vector<int> left(num), right(num);
    for(int i = 0; i < num; ++i) {
        left[i] = tmp;
        tmp = max(tmp, arr[i]);
    }
    tmp = -1;
    for(int i = num-1; i >= 0; --i) {
        right[i] = tmp;
        tmp = max(tmp, arr[i]);
    }
    long long ans = 0;
    for(int i = 0; i < num; ++i) {
        tmp = min(left[i], right[i]) - arr[i];
        tmp = max(0, tmp);
        ans += tmp;
    }
    cout << ans << endl;
}