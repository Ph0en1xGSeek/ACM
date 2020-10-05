#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool isSame(int* pan){
    for(int i = 0; i < 16; i++){
        if(pan[i] != 1)
            return false;
    }
    return true;
}

void flip(int* pan, int pos){
    int x = pos / 4;
    int y = pos % 4;
    pan[pos] = !(pan[pos]);
    for(int i = 0; i < 4; i++){
        pan[4*x + i] = !(pan[4*x + i]);
        pan[4*i + y] = !(pan[4*i + y]);
    }
}

void dfs(int* pan, int cur, int* ans, int curPos, int* result, int* tmpResult){
    if(isSame(pan)){
        *ans = min((int)(*ans), cur);
        for(int i = 0; i < (int)(*ans); i++)
            result[i] = tmpResult[i];
        return;
    }
    if(curPos == 16)
        return;
    dfs(pan, cur, ans, curPos+1, result, tmpResult);
    flip(pan, curPos);
    tmpResult[cur] = curPos;
    dfs(pan, cur+1, ans, curPos+1, result, tmpResult);
    flip(pan, curPos);
}

int main()
{
    int pan[16];
    char row[5];
    int pos = 0;
    int result[16];
    int tmpResult[16];
    for(int i = 0; i < 4; i++){
        scanf("%s", row);
        getchar();
        for(int j = 0; j < 4; j++){
            if(row[j] == '+')
                pan[pos++] = 0;
            else
                pan[pos++] = 1;
        }
    }
    int ans = 20;
    dfs(pan, 0, &ans, 0, result, tmpResult);
    printf("%d\n", ans);
    for(int j = 0; j < ans; j++){
        printf("%d %d\n", result[j]/4 + 1, result[j]%4 + 1);
    }
    return 0;
}
