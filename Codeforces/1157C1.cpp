#include <iostream>
#include <stdio.h>
#define MAXN 200000 + 4

using namespace std;

int main () {
    int m;
    char str[MAXN];
    int arr[MAXN];
    while(~scanf("%d", &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%d", &arr[i]);
        }
        int l = 0, r = m-1;
        int cur = 0;
        int pos = 0;
        while(l <= r) {
            if(cur < arr[l] || cur < arr[r]) {
                if((arr[l] <= arr[r] && cur < arr[l]) || (arr[l] > arr[r] && cur >= arr[r])) {
                    cur = arr[l++];
                    str[pos++] = 'L';
                }else {
                    cur = arr[r--];
                    str[pos++] = 'R';
                }
            }else {
                break;
            }
               
        }
        str[pos++] = '\0';
        printf("%d\n", pos-1);
        printf("%s\n", str);
    }
    return 0;
}