#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    long long n;
    while(cin >> n) {
        if(n <= 1) {
            cout << 0 << endl;
            continue;
        }
        long long sum = 1;
        long long pre = 1;
        long long cur = 1;
        while(sum < n) {
            sum += cur;
            long long tmp = cur + pre;
            pre = cur;
            cur = tmp;
        }
        sum -= pre;
        cout << sum << endl;
    }
    return 0;
}