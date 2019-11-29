#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, l, r;
    while(~scanf("%d%d%d", &n, &l, &r)) {
        int min_ans = (1 << l) - 1 + (n - l);
        int max_ans = (1 << r) -1 + (n - r) * (1 << (r-1));
        printf("%d %d\n", min_ans, max_ans);
    }
    return 0;
}