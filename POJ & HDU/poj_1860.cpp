#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 1e9

using namespace std;

double rate[MAX][MAX];
double com[MAX][MAX];
queue<int> q;
bool isInqueue[MAX];
double dis[MAX];
int n, m, start;
double v;
int c1, c2;

bool spfa(){
    dis[start] = v;
    q.push(start);
    isInqueue[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        isInqueue[cur] = false;
        for(int i = 1; i <= n; i++){
            if(dis[i] < (dis[cur] - com[cur][i])*rate[cur][i]){
                dis[i] = (dis[cur] - com[cur][i])*rate[cur][i];
                if(!isInqueue[i]){
                    q.push(i);
                    isInqueue[i] = true;
                }
            }
        }
        if(dis[start] > v)
            return true;
    }
    return false;
}

int main(){
    while(~scanf("%d%d%d%lf", &n, &m, &start, &v)){
        memset(rate, 0, sizeof(rate));
        memset(com, 0, sizeof(com));
        memset(isInqueue, 0, sizeof(isInqueue));
        for(int i = 0; i < MAX; i++){
            dis[i] = -INF;
        }
        while(!q.empty()){
            q.pop();
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d", &c1, &c2);
            scanf("%lf%lf%lf%lf", &rate[c1][c2], &com[c1][c2], &rate[c2][c1], &com[c2][c1]);
        }
        bool isIncrease = spfa();
        if(isIncrease){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
