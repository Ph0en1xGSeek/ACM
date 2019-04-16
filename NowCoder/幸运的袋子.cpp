#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& arr, int pos, long long sum, long long mul, int& cnt){
    if(pos == arr.size())
        return;
    if(sum + arr[pos] <= mul * arr[pos]){
        return;
    }
    cnt++;
    dfs(arr, pos+1, sum + arr[pos], mul * arr[pos], cnt);
    int i = 1;
    while(pos + i < arr.size() && arr[pos] == arr[pos + i]){
        i++;
    }
    dfs(arr, pos+i, sum, mul, cnt);
}

int main(){
    int num;
    scanf("%d", &num);
    if(num == 0){
        printf("0\n");
    }
    vector<int> arr(num);
    for(int i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    if(arr[0] != 1){
        printf("0\n");
    }
    int cnt = 0;
    dfs(arr, 1, 1, 1, cnt);
    printf("%d\n", cnt);
    return 0;
}
