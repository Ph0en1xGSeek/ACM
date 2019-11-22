#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

char mp[55][55];


int main() {
    int n;
    int tmp;
    int cnt1, cnt2;
    while(~scanf("%d", &n)) {
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            if(tmp == 1) {
                ++cnt1;
            }else {
                ++cnt2;
            }
        }
        if(cnt2 > 0 && cnt1 > 0) {
            --cnt2;
            --cnt1;
            printf("2 1");
        }
        while(cnt2--) {
            printf(" 2");
        }
        while(cnt1--) {
            printf(" 1");
        }
        printf("\n");
    }
    return 0;
}