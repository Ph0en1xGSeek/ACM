#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> arr(num);
    unordered_map<int, int> mp;
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    int pos = 0, left = 0;
    int cur = 0;
    int ans = 0;
    while(pos < num) {
        if(mp.find(arr[pos]) == mp.end()) {
            mp[arr[pos]] = pos;
            ++cur;
            ans = max(ans, cur);
        }else {
            while(left < pos && arr[left] != arr[pos]) {
                mp.erase(arr[left++]);
                --cur;
            }
            ++left;
            mp[arr[pos]] = pos;
        }
        ++pos;
    }
    cout << ans << endl;
    return 0;
}