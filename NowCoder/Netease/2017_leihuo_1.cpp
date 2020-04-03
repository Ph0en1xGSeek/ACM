#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
    string str;
    while(cin >> str) {
        string ans;
        int pos = 0;
        int size = str.size();
        int cnt = 1;
        while(pos < size) {
            if(pos+1 == size || str[pos+1] != str[pos]) {
                string num;
                while(cnt > 0) {
                    num += cnt % 10 + '0';
                    cnt /= 10;
                }
                reverse(num.begin(), num.end());
                ans += num;
                ans.push_back(str[pos]);
                ++pos;
                cnt = 1;
            }else {
                ++cnt;
                ++pos;
            }
        }
        cout << ans << endl;
    }
    return 0;
}