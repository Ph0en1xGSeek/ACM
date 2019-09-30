#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;



int main() {
    int C;
    scanf("%d", &C);
    vector<int> p;
    int n, V, W;
    double ans;
    while(C--) {
        scanf("%d%d%d", &n, &V, &W);
        p.resize(n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
        }
        sort(p.begin(), p.begin()+n);
        double cur_w = 0.0, tmp;
        int i;
        int cur_v = 0;
        for(i = 0; i < n; ++i) {
            tmp = (cur_w * cur_v + p[i] * V) / (cur_v + V);
            if(tmp <= W) {
                cur_v += V;
                cur_w = tmp;
            }else {
                break;
            }
        }
        if(i == 0) {
            printf("0 0.00\n");
        }else {
            printf("%d %.2lf\n", cur_v, cur_w / 100.0);
        }
    }
    return 0;
}