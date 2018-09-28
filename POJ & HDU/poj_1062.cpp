#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
#define MAX_NODE 101
#define INF 0x7fffffff


using namespace std;

int arr[MAX_NODE][MAX_NODE];
int ranks[MAX_NODE];
int cost[MAX_NODE];
int dis[MAX_NODE];
bool isInqueue[MAX_NODE];


int m, n;
int p, l, x;
int t, v;

bool spfa(int pos){
    memset(isInqueue, 0, sizeof(isInqueue));
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dis[i] = cost[i];
        if(ranks[i] >= ranks[1]-m+pos && ranks[i] <= ranks[1]+pos){
            q.push(i);
            isInqueue[i] = true;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        isInqueue[cur] = false;
        for(int i = 1; i <= n; i++){
            if(arr[cur][i] > 0 && (ranks[i] >= ranks[1]-m+pos && ranks[i] <= ranks[1]+pos)){
                if(dis[i] > arr[cur][i] + dis[cur]){
                    dis[i] = arr[cur][i] + dis[cur];
                    if(!isInqueue[i]){
                        isInqueue[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }
}

int main(){
    while(~scanf("%d%d", &m, &n)){
        memset(arr, -1, sizeof(arr));
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &p, &l, &x);
            cost[i] = dis[i] = p;
            ranks[i] = l;
            for(int j = 0; j < x; j++){
                scanf("%d%d", &t, &v);
                arr[t][i] = v;
            }
        }
        int mi = INF;
        for(int i = 0; i <= m; i++){
            spfa(i);
            mi = min(mi, dis[1]);
        }
        printf("%d\n", mi);
    }
    return 0;
}
