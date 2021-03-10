#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<char> ans;
    while(n && m) {
        long long count = 1;
        for(int i = 0; i < n-1; ++i) {
            count *= n - 1 + m - i;
            count /= (i + 1);
            if(count >= k)
                break;
        }
        if(count >= k) {
            ans.push_back('a');
            --n;
        }else {
            ans.push_back('z');
            --m;
            k -= count;
        }
    }
    if(k != 1) {
        printf("-1\n");
        return 0;
    }
    while(n--) {
        ans.push_back('a');
    }
    while(m--) {
        ans.push_back('z');
    }
    for(int i = 0; i  < ans.size(); ++i) {
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}