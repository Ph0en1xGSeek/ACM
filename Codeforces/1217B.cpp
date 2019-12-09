#include <iostream>
#include <stdio.h>


using namespace std;


int main() {
    int t;
    int n;
    long long x, d, h;
    long long ans;
    long long mx_diff, mx_d;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        mx_diff = INT_MIN;
        mx_d = 0;
        cin >> n >> x;
        for(int j = 0; j < n; ++j) {
            cin >> d >> h;
            mx_diff = max(mx_diff, d - h);
            mx_d = max(mx_d, d);
        }
        if(mx_diff <= 0 && mx_d < x) {
            printf("-1\n");
        }else if(mx_diff <= 0 && mx_d >= x) {
            printf("1\n");
        }else {
            ans = max(0ll, x - mx_d + (mx_diff - 1)) / mx_diff;
            ++ans;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
 
 