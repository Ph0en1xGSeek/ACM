#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;


int main() {
    int T;
    int n, a, b;
    string str;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &a, &b);
        cin >> str;
        long long threshold = 2 * a / b + 1;
        int last = -1000000;
        long long num_one_block = 0;
        long long num_one = 0;
        long long sz = str.size();
        for(int i = 1; i < sz; ++i) {
            if(str[i] == '1') {
                ++num_one;
                if(str[i-1] == '0') {
                    ++num_one_block;
                    if(i != 1) {
                        int num_zero = i - last - 1;
                        if(num_zero == 1 || num_zero <= threshold) {
                            num_one += num_zero;
                            --num_one_block;
                        }
                    }
                }
                last = i;
            }
        }
        long long ans = (sz + 2 * num_one_block) * a + ((num_one + num_one_block) * 2 + (sz + 1 - num_one - num_one_block)) * b;
        cout << ans << endl;
    }
    return 0;
}