#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

long long solve(long long n) {
    long long ans = 0;
    long long last_ans = 0;
    long long n_0 = n % 10;
    for(long long i = 0; i <= n_0; ++i) {
        if((n - i) % 9 != 0) {
            ++last_ans;
        }
    }
    long long cnt = 9;
    n /= 10;
    while(n > 0) {
        long long pos = n % 10;
        ans += pos * cnt;
        n /= 10;
        cnt *= 9;
    }
    ans = ans / 9 * 8;
    return last_ans + ans;
}

int main() {
    int t;
    cin >> t;
    long long f, l;
    for(int c = 1; c <= t; ++c) {
        cin >> f >> l;
        long long ans = solve(l) - solve(f) + 1;
        printf("Case #%d: %lld\n", c, ans);
    }
    return 0;
}