#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a: gcd(b, a%b);
}

int main()
{
    int n, m;
    bool flag = false;
    while(~scanf("%d%d", &n, &m)) {
        vector<long long> x(n, 0);
        vector<long long> p(m, 0);
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &x[i]);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%lld", &p[i]);
        }
        long long interval = x[1] - x[0];
        for(int i = 2; i < n && interval != 1; ++i) {
            interval = gcd(interval, x[i] - x[i-1]);
        }
        int pos = -1;
        for(int i = 0; i < m; ++i) {
            if(interval % p[i] == 0) {
                pos = i+1;
                break;
            }
        }
        if(pos < 0) {
            printf("NO\n");
        }else {
            printf("YES\n");
            printf("%lld %d\n", x[0], pos);
        }
    }

    return 0;
}
