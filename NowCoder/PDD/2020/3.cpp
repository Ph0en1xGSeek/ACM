#include <iostream>
#include <vector>

using namespace std;

unsigned long long memo[51][51] = {0};

unsigned long long cnt(int n, int m) {
    if(n == 0) {
        return m;
    }
    if(m == 0) {
        return n;
    }
    if(memo[n][m] != 0) {
        return memo[n][m];
    }
    memo[n][m] = cnt(n-1, m) + cnt(n, m-1) + 2;
    return memo[n][m];
}

int main() {
    int n, m;
    unsigned long long k;
    while(cin >> n >> m >> k) {
        string cur = "";
        while(k > 0 && (n || m)) {
            if(n == 0) {
                cur += 'b';
                --k;
                continue;
            }
            unsigned long long pre_a = cnt(n - 1, m) + 1;
            if(k <= pre_a) {
                cur += 'a';
                --k;
                --n;
            }else {
                cur += 'b';
                k -= pre_a + 1;
                --m;
            }
        }
        cout << cur << endl;
    }
    return 0;
}