#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int main() {
    int n, m, r;
    int tmp; 
    while(~scanf("%d%d%d", &n, &m, &r)) {
        int mx = 0;
        int mi = 2000;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            mi = min(mi, tmp);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d", &tmp);
            mx = max(mx, tmp);
        }
        if(mi >= mx) {
            printf("%d\n", r);
        }else {
            printf("%d\n", r % mi + r / mi * mx);
        }
    }
    return 0;
}