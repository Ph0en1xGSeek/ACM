#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main () {
    int m, n;
    int tmp;
    while(~scanf("%d%d", &n, &m)) {
        int c_odd = 0, c_even = 0, k_odd = 0, k_even = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            if(tmp & 1) {
                ++c_odd;
            }else {
                ++c_even;
            }
        }

        for(int i = 0; i < m; ++i) {
            scanf("%d", &tmp);
            if(tmp & 1) {
                ++k_odd;
            }else {
                ++k_even;
            }
        }
        int ans = min(c_odd, k_even) + min(c_even, k_odd);
        printf("%d\n", ans);
    }
    return 0;
}