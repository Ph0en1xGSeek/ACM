#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool valid(char* wff, int num){
    bool st[101];
    int top = 0;
    int len = strlen(wff);
    for(int i = len-1; i >= 0; i--){
        if(wff[i] == 'p'){
            st[top++] = ((1&num) == 1);
        }else if(wff[i] == 'q'){
            st[top++] = (((1<<1)&num) == (1<<1));
        }else if(wff[i] == 'r'){
            st[top++] = (((1<<2)&num) == (1<<2));
        }else if(wff[i] == 's'){
            st[top++] = (((1<<3)&num) == (1<<3));
        }else if(wff[i] == 't'){
            st[top++] = (((1<<4)&num) == (1<<4));
        }else if(wff[i] == 'K'){
            st[top-2] = (st[top-1] && st[top-2]);
            top--;
        }else if(wff[i] == 'A'){
            st[top-2] = (st[top-1] || st[top-2]);
            top--;
        }else if(wff[i] == 'C'){
            st[top-2] = ((!st[top-2]) || st[top-1]);
            top--;
        }else if(wff[i] == 'E'){
            st[top-2] = (st[top-1] == st[top-2]);
            top--;
        }else if(wff[i] == 'N'){
            st[top-1] = !st[top-1];
        }
    }
    return st[0];
}

int main(){
    char wff[101];
    bool flag;
    while(scanf("%s", wff) && strcmp(wff, "0") != 0){
        flag = true;
        for(int i = 0; i < (1<<5); i++){
            if(valid(wff, i) == false){
                flag = false;
                break;
            }
        }
        if(flag)
            printf("tautology\n");
        else
            printf("not\n");
    }
    return 0;
}
