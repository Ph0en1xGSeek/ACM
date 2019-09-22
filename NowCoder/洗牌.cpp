#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <memory>
#include <vector>

using namespace std;


int main() {
    int T = 0;
    int n, k;
    scanf("%d", &T);
    vector<int> arr, ans, nex;
    while(T--) {
        scanf("%d%d", &n, &k);
        n <<= 1;
        arr.resize(n);
        ans.resize(n);
        nex.resize(n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        if(n <= 2) {
            printf("%d %d\n", arr[0], arr[1]);
            continue;
        }
        ans[0] = arr[0];
        ans[n-1] = arr[n-1];
        for(int i = 1; i < n-1; ++i) {
            if(i < n / 2) {
                nex[i] = 2 * i;
            }else {
                nex[i] = 2 * (i - (n / 2)) + 1;
            }
        }
        

        for(int i = 1; i < n-1; ++i) {
            int pos = i;
            for(int j = 0; j < k; ++j) {
                pos = nex[pos];
            }
            ans[pos] = arr[i];
        }
        printf("%d", ans[0]);
        for(int i = 1; i < n; ++i) {
            printf(" %d", ans[i]);
        }
        printf("\n");
        
    }
    return 0;
}