#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#define M 2000

using namespace std;

char t[M][10];
int arr[M][M];
bool vis[M];
int num;

struct node{
    int num;
    int len;
    bool operator<(const node &b) const{
        return len > b.len;
    }
};

int dist(int a, int b){
    int cnt = 0;
    for(int i = 0; i < 7; i++){
        if(t[a][i] != t[b][i])
            cnt++;
    }
    return cnt;
}

int prim(int start){
    int ans = 0;
    priority_queue<node> q;
    memset(vis, 0, sizeof(vis));
    node tmp;
    tmp.num = start;
    tmp.len = 0;
    q.push(tmp);
    for(int k = 0; k < num; k++){
        node cur;
        do{
            cur = q.top();
            q.pop();
        }while(vis[cur.num]);
        vis[cur.num] = true;
        ans += cur.len;
        for(int i = 0; i < num; i++){
            if(!vis[i]){
                node tmp;
                tmp.num = i;
                tmp.len = arr[cur.num][i];
                q.push(tmp);
            }
        }
    }
    return ans;
}

int main(){
    while(~scanf("%d", &num) && num != 0){
        for(int i = 0; i < num; i++){
            scanf("%s", t[i]);
        }
        for(int i = 0; i < num; i++){
            arr[i][i] = 0;
            for(int j = i+1; j < num; j++){
                arr[i][j] = arr[j][i] = dist(i, j);
            }
        }
        int ans = prim(0);
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}
