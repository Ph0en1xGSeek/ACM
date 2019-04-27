#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int tmp;
    vector<int> h, w;
    while(~scanf("%d", &n)) {
        h.clear();
        w.clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            h.push_back(tmp);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", &tmp);
            w.push_back(tmp);
        }
        if(n == 0 || m == 0) {
            printf("0\n");
            continue;
        }
        sort(h.begin(), h.begin() + n);
        sort(w.begin(), w.begin() + m);
        int i = 0, j = 0;
        while(i != n && j != m) {
            if(h[i] <= w[j]){
                ++i;
                ++j;
            }else {
                ++j;
            }
        }
        printf("%d\n", i);
    }
    return 0;
}
