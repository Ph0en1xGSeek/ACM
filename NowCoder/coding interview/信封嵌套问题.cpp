#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    while(cin >> num) {
        vector<pair<int, int>> arr(num);
        for(int i = 0; i < num; ++i) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b){
            if(a.first == b.first) {
                return  a.second > b.second;
            }
            return a.first < b.first;
        });
        int pos = 0;
        vector<int> dp;
        while(pos < num) {
            auto iter = lower_bound(dp.begin(), dp.end(), arr[pos].second);
            if(iter == dp.end()) {
                dp.push_back(arr[pos].second);
            }else {
                *iter = arr[pos].second;
            }
            ++pos;
        }
        cout << dp.size() << endl;
    }
    return 0;
}