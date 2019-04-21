#include <iostream>
#include <stdio.h>

int main(){
    int f[32];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= 31; i++){
        f[i] = f[i-1] + f[i-2];
    }
    int num;
    scanf("%d", &num);
    int i;
    for(i = 0; i < 32 && f[i] < num; i++);
    int ans = std::min(num - f[i-1], f[i] - num);
    printf("%d\n", ans);
    return 0;
}
