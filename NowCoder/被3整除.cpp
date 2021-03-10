#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt(int x) {
    return (x / 3) * 2 + max( x % 3 - 1, 0);
}


int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = cnt(r) - cnt(l-1);
    printf("%d\n", ans);
    return 0;
}