#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#define MAX_NODE 501
#define MAX_EDGE 5402
#define INF 1e9


using namespace std;

int ca, n, m, w;

int head[MAX_NODE];
int cnt;
int dis[MAX_NODE];
bool isInqueue[MAX_NODE];
int num_inqueue[MAX_NODE];

struct edge{
    int v;
    int cap;
    int nex;
}edges[MAX_EDGE];

void add(int s, int t, int cap){
    edges[cnt].cap = cap;
    edges[cnt].v = t;
    edges[cnt].nex = head[s];
    head[s] = cnt++;
}

bool spfa(int start){
    queue<int> q;
    while(!q.empty())
        q.pop();
    memset(num_inqueue, 0, sizeof(num_inqueue));
    memset(isInqueue, false, sizeof(isInqueue));
    for(int i = 0; i < MAX_NODE; i++)
        dis[i] = INF;
    dis[start] = 0;
    q.push(start);
    isInqueue[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        isInqueue[cur] = false;
        for(int pos = head[cur]; pos != -1; pos = edges[pos].nex){
            int v = edges[pos].v;
            if(dis[v] > dis[cur] + edges[pos].cap){
                dis[v] = dis[cur] + edges[pos].cap;
                if(!isInqueue[v]){
                    q.push(v);
                    isInqueue[v] = true;
                    num_inqueue[v]++;
                    if(num_inqueue[v] >= n)
                        return true;
                }
            }
        }
    }
    return false;
}


int main(){
    int from, to, cap;
    scanf("%d", &ca);
    while(ca--){
        cnt = 0;
        memset(head, -1, sizeof(head));
        scanf("%d%d%d", &n, &m, &w);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &from, &to, &cap);
            add(from, to, cap);
            add(to, from, cap);
        }
        for(int i = 0; i < w; i++){
            scanf("%d%d%d", &from, &to, &cap);
            add(from, to, -cap);
        }
        bool ans = spfa(1);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
