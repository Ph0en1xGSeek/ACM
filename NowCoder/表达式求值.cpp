#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    int arr[3];
    for(int i = 0; i < 3; ++i) {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    int tmp;
    tmp = arr[1] + arr[2];
    ans = max(tmp + arr[0], ans);
    ans = max(tmp * arr[0], ans);
    
    tmp = arr[1] * arr[2];
    ans = max(tmp + arr[0], ans);
    ans = max(tmp * arr[0], ans);
    
    tmp = arr[0] + arr[1];
    ans = max(tmp + arr[2], ans);
    ans = max(tmp * arr[2], ans);
    
    tmp = arr[0] * arr[1];
    ans = max(tmp + arr[2], ans);
    ans = max(tmp * arr[2], ans);
    
    printf("%d\n", ans);
    return 0;
}