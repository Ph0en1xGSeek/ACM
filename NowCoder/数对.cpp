#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if(k == 0) {
        printf("%lld\n", (long long)n*n);
    }else if(n <= k) {
        printf("0\n");
    }else {
        long long ans = 0;
        for(int y = k+1; y <= n; ++y) {
            ans += (n / y) * (y - k) + max(n % y - k + 1, 0);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}