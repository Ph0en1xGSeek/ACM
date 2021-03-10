#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int size = str.size();
    int cnt_R = 0, cnt_G = 0;
    for(int i = 0; i < size; ++i) {
        if(str[i] == 'G') {
            ++cnt_G;
        }
    }
    int ans = cnt_G;
    for(int i = size - 1; i >= 0; --i) {
        ans = min(ans, cnt_R + cnt_G);
        if(str[i] == 'G') {
            --cnt_G;
        }else {
            ++cnt_R;
        }
    }
    ans = min(ans, cnt_R + cnt_G);
    cout << ans << endl;
    return 0;
}