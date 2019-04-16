#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define MAX_NODE 105
#define INF 150000

using namespace std;

struct Edge{
    int from;
    int to;
    int cap;
    int flow;
    Edge(int f, int t, int c, int fw){
        from = f;
        to = t;
        cap = c;
        flow = fw;
    }
};

vector<Edge> edges;
vector<int> mp[MAX_NODE], prefix[MAX_NODE]; //the suffix edges of every node, the prefix nodes of every node
int deep[MAX_NODE], num[MAX_NODE], cur[MAX_NODE], pre[MAX_NODE];
int n, np, nc, m;

void add(int from, int to, int cap){
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    int sz = edges.size();
    mp[from].push_back(sz-2);
    mp[to].push_back(sz-1);
}

void bfs(int s, int t){
    memset(deep, -1, sizeof(deep));
    queue<int> q;
    q.push(s);
    deep[s] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < prefix[cur].size(); i++){
            int to = prefix[cur][i];
            if(deep[to] < 0){
                deep[to] = deep[cur] + 1;
                q.push(to);
            }
        }
    }
}

int augument(int s, int t){
    int pos = t;
    int flow = INF;
    while(pos != s){
        Edge &e = edges[pre[pos]];
        flow = min(flow, e.cap - e.flow);
//        printf("flow %d\n", flow);
//        printf("%d %d\n", e.cap, e.flow);
        pos = e.from;
    }
    pos = t;
    while(pos != s){
        edges[pre[pos]].flow += flow;
        edges[pre[pos]^1].flow -= flow;
        pos = edges[pre[pos]].from;
    }
    return flow;
}

int ISAP(int s, int t){
    int flow = 0;
    bool flag = false;
    bfs(t, s);
    memset(cur, 0, sizeof(cur));
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; i++){
        num[deep[i]]++;
    }
    int pos = s;
    while(deep[s] < n){
        if(pos == t){
            //augument one path successfully
            flow += augument(s, t);
            //continue the next one
            pos = s;
        }
        flag = false;
        for(int i = cur[pos]; i < mp[pos].size(); i++){
            Edge &e = edges[mp[pos][i]];
            if(e.cap > e.flow && deep[pos] == deep[e.to] + 1){
                flag = true;
                cur[pos] = i;
                pre[e.to] = mp[pos][i];
                pos = e.to;
                break;
            }
        }
        if(flag == false){
            int mi = n-1;
            for(int i = 0; i < mp[pos].size(); i++){
                Edge &e = edges[mp[pos][i]];
                if(e.cap > e.flow){
                    mi = min(mi, deep[e.to]);
                }
            }
            //gap
            num[deep[pos]]--;
            if(num[deep[pos]] == 0)
                break;
            num[mi+1]++;
            deep[pos] = mi+1;
            cur[pos] = 0;
            if(pos != s)
                pos = edges[pre[pos]].from;
        }
    }
    return flow;
}


int main(){
    while(~scanf("%d%d%d%d", &n, &np, &nc, &m)){
        n += 2;
        for(int i = 0; i < n; i++){
            mp[i].clear();
            prefix[i].clear();
        }
        edges.clear();
        int from, to, cap;
        for(int i = 0; i < m; i++){
            scanf(" (%d,%d)%d", &from, &to, &cap);
            add(from, to, cap);
            prefix[to].push_back(from);
        }
        for(int i = 0; i < np; i++){
            scanf(" (%d)%d", &from, &cap);
            add(n-2, from, cap);
            prefix[from].push_back(n-2);
        }
        for(int i = 0; i < nc; i++){
            scanf(" (%d)%d", &from, &cap);
            add(from, n-1, cap);
            prefix[n-1].push_back(from);
        }
        int ans = ISAP(n-2, n-1);
        printf("%d\n", ans);
    }
    return 0;
}
