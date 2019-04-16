#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

bool isPalindrom(int num){
    vector<int> arr;
    while(num > 0){
        arr.push_back(num % 10);
        num /= 10;
    }
    int len = arr.size();
    for(int i = 0; i < (len+1) / 2; i++){
        if(arr[i] != arr[len-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    printf("1\n2\n3\n11\n");
    for(int i = 12; i < 256; i++){
        int pow = i * i;
        if(isPalindrom(pow)){
            printf("%d\n", i);
        }
    }
    return 0;
}
