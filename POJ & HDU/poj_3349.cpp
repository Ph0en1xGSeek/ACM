#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX 100005
#define KEY 100000

using namespace std;

int snowFlakes[MAX][6];
vector<int> head[KEY];

bool isSame(int a, int b){
    for(int i = 0; i < 6; i++){
        bool flag = true;
        for(int j = 0; j < 6; j++){
            if(snowFlakes[a][j] != snowFlakes[b][(i+j)%6]){
                flag = false;
                break;
            }
        }
        if(flag == true)
            return true;
    }
    for(int i = 0; i < 6; i++){
        bool flag = true;
        for(int j = 0; j < 6; j++){
            if(snowFlakes[a][j] != snowFlakes[b][(i-j+6)%6]){
                flag = false;
                break;
            }
        }
        if(flag == true)
            return true;
    }
    return false;
}

int main(){
    int num, sum;
    bool flag = false;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        sum = 0;
        for(int j = 0; j < 6; j++){
            scanf("%d", &snowFlakes[i][j]);
            sum += snowFlakes[i][j];
        }
        if(flag == false){
            int key = sum % KEY;
            if(head[key].size() > 0){
                for(int j = 0; j < head[key].size(); j++){
                    if(isSame(head[key][j], i)){
                        flag = true;
                        break;
                    }
                }
            }
            head[key].push_back(i);
        }
    }
    if(flag){
        printf("Twin snowflakes found.\n");
    }else{
        printf("No two snowflakes are alike.\n");
    }
    return 0;
}
