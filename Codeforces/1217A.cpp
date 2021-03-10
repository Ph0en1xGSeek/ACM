#include <iostream>
#include <stdio.h>


using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    int str, intell, exp;
    int ans;
    for(int i = 0; i < t; ++i) {
        scanf("%d%d%d", &str, &intell, &exp);
        int dif = str - intell;
        if(dif > 0) {
            ans = exp + 1 - max(0, exp - dif + 2) / 2;
        }else {
            ans = max(0, exp + dif + 1) / 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
 
 