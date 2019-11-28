#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    string str;
    bool add;
    while(cin >> str) {
        add = false;
        int sz = str.size();
        int ans = (sz-1) / 2;
        if((sz-1) % 2) {
            ++ans;
            add = true;
        }
        for(int i = 1; i < sz && !add; ++i) {
            if(str[i] != '0') {
                ++ans;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}