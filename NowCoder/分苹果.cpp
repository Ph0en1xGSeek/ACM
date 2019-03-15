#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
    int num;
    int arr[101];
    scanf("%d", &num);
    int sum = 0;
    bool odd = false;
    bool even = false;
    for (int i =0; i < num; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] % 2 == 0){
            even = true;
        }else{
            odd = true;
        }
    }
    if(sum % num != 0 || (even && odd)){
        printf("-1\n");
    }else{
        sum /= num;
        int ans = 0;
        for(int i = 0; i < num; i++){
            if(arr[i] < sum){
                ans += sum - arr[i];
            }
        }
        ans /= 2;
        printf("%d\n", ans);
    }
    return 0;
}