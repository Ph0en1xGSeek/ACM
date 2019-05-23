#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t, n, k;
    scanf("%d", &t);
    double sum;
    double tmp_e;
    for(int c = 1; c <= t; ++c) {
        scanf("%d%d", &n, &k);
        sum = 0;
        vector<long long> arr(n);
        vector<long long> suffix_sum(n);
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }
        tmp_e = sum / n;
        sort(arr.begin(), arr.end());
        suffix_sum[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i+1] + arr[i];
        }
        for(int i = 0; i < k; ++i) {
            int l = 0, r = n-1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(arr[mid] < tmp_e) {
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
            if(l == 0) {
                tmp_e = arr[0];
                break;
            }else {
                tmp_e = (l * tmp_e + suffix_sum[l]) / n;
            }
        }
        printf("Case #%d: %.6lf\n", c, tmp_e);
    }
    return 0;
}