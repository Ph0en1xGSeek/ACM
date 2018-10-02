#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool isSame(int* pan){
    for(int i = 1; i < 16; i++){
        if(pan[i] != pan[i-1])
            return false;
    }
    return true;
}

void flip(int* pan, int pos){
    int x = pos / 4;
    int y = pos % 4;
    pan[pos] = !(pan[pos]);
    if(y < 3){
        pan[pos+1] = !(pan[pos+1]);
    }
    if(y > 0){
        pan[pos-1] = !(pan[pos-1]);
    }
    if(x < 3){
        pan[pos + 4] = !(pan[pos + 4]);
    }
    if(x > 0){
        pan[pos - 4] = !(pan[pos - 4]);
    }
}

bool dfs(int* pan, int cur, int len, int curPos){
    if(cur == len)
        if(isSame(pan)){
            return true;
        }
    else
        return false;
    if(16 - curPos < len - cur)
        return false;
    int* new_pan = new int[16];
    for(int i = curPos; i < 16; i++){
        for(int j = 0; j < 16; j++){
            new_pan[j] = pan[j];
        }
        flip(new_pan, i);
        if(dfs(new_pan, cur+1, len, i+1)){
            return true;
        }
    }
    return false;
}

int main()
{
    int pan[16];
    char row[5];
    int pos = 0;
    for(int i = 0; i < 4; i++){
        scanf("%s", row);
        getchar();
        for(int j = 0; j < 4; j++){
            if(row[j] == 'b')
                pan[pos++] = 0;
            else
                pan[pos++] = 1;
        }
    }
    if(isSame(pan)){
        printf("0\n");
    }else{
        int ans;
        int i;
        for(i = 1; i <= 16; i++){
            /*number of flipped*/
            if(dfs(pan, 0, i, 0)){
                printf("%d\n", i);
                break;
            }
        }
        if(i == 17)
            printf("Impossible\n");
    }
    return 0;
}
