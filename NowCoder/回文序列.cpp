#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int cnt;
    int l = 0, r = n-1;
    int cnt_l = arr[l];
    int cnt_r = arr[r];
    while(l < r) {
        if(cnt_l > cnt_r) {
            --r;
            cnt_r += arr[r];
            ++cnt;
        }else if(cnt_l < cnt_r) {
            ++l;
            cnt_l += arr[l];
            ++cnt;
        }else {
            ++l;
            --r;
            cnt_l = arr[l];
            cnt_r = arr[r];
        }
    }
    printf("%d\n", cnt);
    return 0;
}