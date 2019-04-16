#include <bits/stdc++.h>
#define mod 1000000007
#define MAX_TIME 100000

using namespace std;

int main(){
    long long x_0[3];
    scanf("%lld", &x_0[0]);
    for(int i = 1; i <= 2; i++){
        x_0[i] = ((long long)x_0[i-1] * 4 + 3) % mod;
    }
    int ans = INT_MAX;
    int tmp;
    for(int i = 0; i < 3; i++){
        tmp = i;
        while(x_0[i] != 0 && tmp <= MAX_TIME){
            x_0[i] = ((long long)x_0[i] * 8 + 7) % mod;
            tmp++;
        }
        ans = min(ans, tmp);
    }
    if(ans > MAX_TIME){
        printf("%d\n", -1);
    }else{
        printf("%d\n", ans);
    }
    return 0;
}
