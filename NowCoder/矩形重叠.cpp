#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x1[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &y1[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x2[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &y2[i]);
    }
    int ans = 0;
    int tmp;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x = x1[i];
            int y = y1[j];
            tmp = 0;
            for(int k = 0; k < n; ++k) {
                if(x >= x1[k] && x < x2[k] && y >= y1[k] && y < y2[k]) {
                    ++tmp;
                }
            }
            ans = max(ans, tmp);
        }
    }
    printf("%d\n", ans);
    return 0;
}