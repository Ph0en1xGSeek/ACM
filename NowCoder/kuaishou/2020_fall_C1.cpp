#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int k;
    string str;
    while(cin >> k >> str) {
        int size = str.size();
        vector<int> accu(size+1, 0);
        for(int i = 1; i <= size; ++i) {
            accu[i] = accu[i-1] + str[i-1] - '0';
        }
        long long ans = 0;
        for(auto iter = accu.begin(); iter != accu.end(); ++iter) {
            auto upper = upper_bound(iter+1, accu.end(), (*iter) + k);
            auto lower = lower_bound(iter+1, accu.end(), (*iter) + k);
            ans += upper - lower;
        }
        cout << ans << endl;
    }
    return 0;
}