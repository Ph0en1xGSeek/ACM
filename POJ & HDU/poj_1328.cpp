#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

struct land{
    double l;
    double r;
    int y;
    bool operator<(const land& b) const{
        if(r == b.r){
            return l < b.l;
        }
        return r < b.r;
    }
}lands[1000];


int main()
{
    int n, d;
    int cas = 1;
    bool flag = true;
    int cnt = 1;
    while(~scanf("%d%d", &n, &d) && n != 0){
        flag = true;
        cnt = 1;
        int x;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x, &lands[i].y);
            if(lands[i].y > d || lands[i].y < 0)
                flag = false;
            lands[i].l = x - sqrt(d*d - lands[i].y*lands[i].y);
            lands[i].r = x + sqrt(d*d - lands[i].y*lands[i].y);
        }
        if(flag == false){
            printf("Case %d: %d\n", cas++, -1);
            continue;
        }
        sort(lands, lands+n);
        double cur = lands[0].r;
        for(int i = 1; i < n; i++){
            if(lands[i].l > cur){
                cur = lands[i].r;
                cnt++;
            }
        }
        printf("Case %d: %d\n", cas++, cnt);
    }
    return 0;
}
