#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

typedef struct node {
    int j;
    int f;
    bool operator<(const node &b) const {
        return (double)j / f > (double)b.j / b.f;
    }
}node;


int main() {
    int m, n;
    vector<node> arr;
    while(~scanf("%d%d", &m, &n) && m != -1) {
        arr.resize(n);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &arr[i].j, &arr[i].f);
        }
        sort(arr.begin(), arr.end());
        double ans = 0.0;
        int i;
        for(i = 0; i < n && m > arr[i].f; ++i) {
            m -= arr[i].f;
            ans += arr[i].j;
        }
        if(i < n)
            ans += m * (double)arr[i].j / arr[i].f;
        printf("%.3lf\n", ans);
    }
    return 0;
}