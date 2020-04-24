#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    int target;
    cin >> num >> target;
    vector<int> arr(num);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int cur = 0;
    int ans = 0;
    int pos = 0;
    while(cur < target) {
        if(pos == num) {
            ++ans;
            cur += cur + 1;
        }else if(arr[pos] > cur + 1) {
            ++ans;
            cur += cur + 1;
        }else {
            cur += arr[pos];
            ++pos;
        }
    }
    cout << ans << endl;
    return 0;
}