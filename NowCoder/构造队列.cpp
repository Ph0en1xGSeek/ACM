#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    deque<int> dq;
    while(T--) {
        int n;
        dq.clear();
        scanf("%d", &n);
        for(int i = n; i >= 1; --i) {
            dq.push_front(i);
            int x = dq.back();
            dq.pop_back();
            dq.push_front(x);
        }
        printf("%d", dq[0]);
        for(int i = 1; i < n; ++i) {
            printf(" %d", dq[i]);
        }
        printf("\n");
    }
    return 0;
}