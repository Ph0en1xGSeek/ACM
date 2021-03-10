#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;


int main() {
    int t;
    int b, p, f;
    int h, c;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ++ca) {
        scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
        int ans = 0;
        int num_h;
        int num_c;
        if(h > c) {
            num_h = (b / 2) > p? p: (b / 2);
            b -= 2 * (num_h);
            num_c = (b / 2) > f? f: max(0, (b / 2));
            ans = num_h * h + num_c * c;
        }else {
            num_c = (b / 2) > f? f: (b / 2);
            b -= 2 * (num_c);
            num_h = (b / 2) > p? p: max(0, (b / 2));
            ans = num_h * h + num_c * c;
        }
        printf("%d\n", ans);
    }
    return 0;
}