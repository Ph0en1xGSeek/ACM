#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> wan;
    vector<int> ying;
    for(int i = 2; i <= 60; i++){
        int tmp = 0;
        for(int j = 1; j * 2 <= i; j++){
            if(i % j == 0){
                tmp += j;
            }
        }
        if(tmp == i){
            wan.push_back(i);
        }else if(tmp > i){
            ying.push_back(i);
        }
    }
    printf("E:");
    for(int i = 0; i < wan.size(); i++){
        printf(" %d", wan[i]);
    }
    printf(" G: 2");
    for(int i = 0; i < ying.size(); i++){
        printf(" %d", ying[i]);
    }
    printf("\n");
    return 0;
}
