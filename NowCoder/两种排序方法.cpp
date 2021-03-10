#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int num;
    scanf("%d", &num);
    bool flag1 = true, flag2 = true;
    char str1[105];
    char str2[105];
    char *pre = str1;
    char *cur = str2;
    scanf("%s", pre);
    for(int i = 1; i < num; i++){
        scanf("%s", cur);
        if(flag1 && strcmp(pre, cur) > 0){
            flag1 = false;
        }
        if(flag2 && strlen(pre) > strlen(cur)){
            flag2 = false;
        }
        swap(pre, cur);
    }
    if(flag1 && flag2){
        printf("both\n");
    }else if(flag1){
        printf("lexicographically\n");
    }else if(flag2){
        printf("lengths\n");
    }else{
        printf("none");
    }
    return 0;
}
