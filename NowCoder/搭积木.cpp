#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
    int x;
    int y;
    node(int _x, int _y) {
        x = _x;
        y = _y;
    }
    node() {
        x = 0;
        y = 0;
    }
    bool operator<(const node &b) const {
        if(x == b.x) {
            return y < b.y;
        }
        return x < b.x;
    }
};

node arr[1000007];
int dp[1000007];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].x, &arr[i].y);
    }
    sort(arr, arr+n);
    int sz = 0;
    dp[sz++] = arr[0].y;
    for(int i = 1; i < n; ++i) {
        if (arr[i].y >= dp[sz-1]) {
            dp[sz++] = arr[i].y;
            continue;
        }
        int l = 0;
        int r = sz - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(dp[mid] <= arr[i].y) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        dp[l] = arr[i].y;
    }
    printf("%d\n", sz);
    return 0;
}