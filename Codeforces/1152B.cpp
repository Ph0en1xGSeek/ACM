#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int check(int x) {
    int pos = -1;
    int cnt = 0;
    while(x > 0) {
        ++cnt;
        if((x & 1) == 0) {
            pos = cnt;
        }
        x >>= 1;
    }
    return pos;
}

int main () {
    int x;
    int cnt, pos;
    vector<int> ans;
    while(~scanf("%d", &x)) {
        ans.clear();
        cnt = 0;
        while(1) {
            pos = check(x);
            if(pos == -1) {
                break;
            }
            ++cnt;
            x ^= ((1 << pos) - 1);
            ans.push_back(pos);
            pos = check(x);
            if(pos == -1) {
                break;
            }
            ++cnt;
            x += 1;
        }
        printf("%d\n", cnt);
        for(int i = 0; i < ans.size(); ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}