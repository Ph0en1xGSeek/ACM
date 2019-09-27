#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num;
    vector<int> arr1, arr2;
    while(~scanf("%d", &num) && num != 0) {
        arr1.resize(num);
        arr2.resize(num);
        for(int i = 0; i < num; ++i) {
            scanf("%d", &arr1[i]);
        }
        for(int i = 0; i < num; ++i) {
            scanf("%d", &arr2[i]);
        }
        sort(arr1.begin(), arr1.end(), greater<int>());
        sort(arr2.begin(), arr2.end(), greater<int>());

        int l1 = 0, l2 = 0, r1 = num-1, r2 = num-1;
        int ans = 0;
        while(l1 <= r1) {
            if(arr1[l1] > arr2[l2]) {
                ans += 200;
                ++l1;
                ++l2;
            }else if(arr1[l1] < arr2[l2]) {
                ans -= 200;
                --r1;
                ++l2;
            }else if(arr1[r1] > arr2[r2]) {
                ans += 200;
                --r1;
                --r2;
            }else {
                if(arr1[r1] < arr2[l2]) 
                    ans -= 200;
                --r1;
                ++l2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}