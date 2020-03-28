#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int num, tmp, sum, right, ans;
    while(cin >> num) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        sum = 0;
        ans = 0;
        right = -1;
        for(int i = 0; i < num; ++i) {
            cin >> tmp;
            sum ^= tmp;
            if(mp.find(sum) != mp.end() && mp[sum] >= right) {
                right = i;
                ++ans;
            }
            mp[sum] = i;
        }
        cout << ans << endl;
    }
    return 0;
}