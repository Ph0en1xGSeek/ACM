#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i * i * 2 <= n; ++i) {
        int tmp = n - i * i;
        int r = static_cast<int>(sqrt(tmp));
        if(r * r == tmp) {
            if(r == i || i == 0) {
                cnt += 4;
            }else {
                cnt += 8;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}