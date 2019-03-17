#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int sum[102];
int n;
long long k;

int lowbit(int x){
    return x & (-x);
}

void update(int pos, int num){
    while(pos <= n){
        sum[pos] += num;
        pos += lowbit(pos);
    }
}

int getsum(int pos){
    int ans = 0;
    while(pos > 0){
        ans += sum[pos];
        pos -= lowbit(pos);
    }
    return ans;
}

int main(){
    int arr[102];
    bool isExist[102];
    memset(isExist, false, sizeof(isExist));
    vector<int> pos;
    vector<int> nums;
    int result = 0;
    scanf("%d %lld", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] != 0){
            isExist[arr[i]] = true;
        }else{
            pos.push_back(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(isExist[i] == false){
            nums.push_back(i);
        }
    }
    do{
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < nums.size(); i++){
            arr[pos[i]] = nums[i];
        }
        long long cnt = 0;
        for(int i = 1; i <= n; i++){
            update(arr[i], 1);
            cnt += getsum(arr[i]) - 1;
        }
        if(cnt == k){
            result++;
        }
    }while(next_permutation(nums.begin(), nums.end()));
    printf("%d\n", result);
    return 0;
}
