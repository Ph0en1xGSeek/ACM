#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int ca;
    string str;
    cin >> ca;
    while(ca--) {
        cin >> str;
        int size = str.size();
        if(size <= 2) {
            cout << size << endl;
            continue;
        }
        vector<int> accu(size + 1, 0);
        for(int i = 1; i <= size; ++i) {
            if(str[i-1] != 'N') {
                accu[i] = accu[i-1] + 1;
            }else {
                accu[i] = accu[i-1];
            }
        }
        int ans = 0;
        for(auto iter = accu.begin(); iter != accu.end(); ++iter) {
            auto end_iter = upper_bound(accu.begin(), accu.end(), (*iter) + 2);
            int diff = end_iter - iter;
            ans = max(ans, diff - 1);
            if(end_iter == accu.end()) {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}