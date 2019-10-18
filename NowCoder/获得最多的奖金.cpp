#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    vector<long long> arr(num);
    for(int i = 0; i < num; ++i) {
        scanf("%lld", &arr[i]);
    }
    int i = 0;
    int j = num-1;
    long long l_sum = arr[i], r_sum = arr[j]; 
    long long ans = 0;
    while(i < j) {
        if(l_sum == r_sum) {
            ans = l_sum;
            l_sum += arr[++i];
            r_sum += arr[--j];
        }else if(l_sum < r_sum) {
           l_sum += arr[++i];
        }else {
            r_sum += arr[--j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}