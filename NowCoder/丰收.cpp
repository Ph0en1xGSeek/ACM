#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int num;
    int tmp;
    scanf("%d", &num);
    vector<int> arr(num);
    scanf("%d", &arr[0]);
    for(int i = 1; i < num; ++i) {
        scanf("%d", &tmp);
        arr[i] = arr[i-1] + tmp;
    }
    int m, q;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &q);
        int left = 0;
        int right = num-1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(arr[mid] >= q) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        printf("%d\n", left+1);
    }
    return 0;
}