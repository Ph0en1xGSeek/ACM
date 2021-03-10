#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define mod 1000000007
#define MAXN 1000005

using namespace std;

int A[MAXN];

int pow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) {
            ans = (long long)ans * a % mod;
        }
        a = (long long)a * a % mod;
        b >>= 1;
    }
    return ans;
}

int sum(int a, int b) {
    if(b == 1) {
        return a;
    }
    int ret = (long long)sum(a, b >> 1) * (1 + pow(a, b >> 1)) % mod;
    if(b & 1) {
        ret += pow(a, b);
        if(ret >= mod) {
            ret -= mod;
        }
        // ret = (ret + pow(a, b)) % mod;
    }
    return ret;
}


int main() {
    int N, K, F;
    long long x, y, C, D, E1, E2;
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        cin >> N >> K >> x >> y >> C >> D >> E1 >> E2 >> F;
        A[1] = (x + y) % F;
        for(int i = 2; i <= N; ++i) {
            int new_x = (C * x + D * y + E1) % F;
            y = (D * x + C * y + E2) % F;
            x = new_x;
            A[i] = (x + y) % F;
        }
        int ret = 0;
        int s = 0;
        for(int i = 1; i <= N; ++i) {
            s += sum(i, K);
            if(s >= mod) {
                s -= mod;
            }
            // s = (s + sum(i, K)) % mod;
            ret += ((long long) A[i] * (N - i + 1) % mod * s) % mod;
            if(ret >= mod) {
                ret -= mod;
            }
            // ret = (ret + ((long long)A[i-1] * (N - i + 1) % mod * s) % mod) % mod;
        }
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}