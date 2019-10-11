#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> arr(n);
    vector<int> wake(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &wake[i]);
    }
    int gain = 0, mx_gain = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += wake[i] * arr[i];
        gain += (1 - wake[i]) * arr[i];
        if(i >= k) {
           gain -= (1 - wake[i - k]) * arr[i-k];
        }
        mx_gain = max(mx_gain, gain);
    }
    sum += mx_gain;
    printf("%d\n", sum);
    return 0;
}