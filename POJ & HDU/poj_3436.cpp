#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define M 105
#define INF 10005

using namespace std;

struct Edge{
    int from;
    int to;
    int flow;
    int cap;
    Edge(int f, int t, int fl, int c){
        from = f;
        to = t;
        cap = c;
        flow = fl;
    }
};

int p, n;
int in[M][10], out[M][10];
vector<Edge> edges;
vector<int> head[M], prefix[M];
int deep[M], num[M], cur[M], pre[M];

void add(int from, int to, int cap){
    edges.push_back(Edge(from, to, 0, cap));
    edges.push_back(Edge(to, from, 0, 0));
    int sz = edges.size();
    head[from].push_back(sz-2);
    head[to].push_back(sz-1);
}

void bfs(int s, int t){
    memset(deep, -1, sizeof(deep));
    memset(num, 0, sizeof(num));
    queue<int> q;
    q.push(s);
    deep[s] = 0;
    num[deep[s]]++;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < prefix[cur].size(); i++){
            int to = prefix[cur][i];
            if(deep[to] < 0){
                deep[to] = deep[cur] + 1;
                num[deep[to]]++;
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
    bool flag;
    bfs(t, s);
    int pos = s;
    memset(cur, 0, sizeof(cur));
    while(deep[s] < 2*(n+1)){
//        cout << flow << " " << pos << " " << deep[pos] << endl;
        if(pos == t){
            flow += augument(s, t);
            pos = s;
        }
        flag = false;
        for(int i = cur[pos]; i < head[pos].size(); i++){
            Edge &e = edges[head[pos][i]];
            if(e.cap > e.flow && deep[pos] == deep[e.to] + 1){
                flag = true;
                cur[pos] = i;
                pre[e.to] = head[pos][i];
                pos = e.to;
                break;
            }
        }
        if(flag == false){
            int mi = 2*n+1;
            for(int i = 0; i < head[pos].size(); i++){
                Edge &e = edges[head[pos][i]];
                if(e.cap > e.flow){
                    mi = min(mi, deep[e.to]);
                }
            }
            num[deep[pos]]--;
            if(num[deep[pos]] == 0) break;
            deep[pos] = mi+1;
            num[deep[pos]]++;
            cur[pos] = 0;
            if(pos != s)
                pos = edges[pre[pos]].from;
        }
    }
    return flow;
}

int main(){
    int tmp;
    bool one, zero, flag;
    while(~scanf("%d%d", &p, &n)){
        edges.clear();
        for(int i = 0; i < 2*n+2; i++){
            head[i].clear();
            prefix[i].clear();
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            add(i, i+n, tmp);
            prefix[i+n].push_back(i);
            one = false;
            for(int j = 0; j < p; j++){
                scanf("%d", &in[i][j]);
                if(in[i][j] == 1)
                    one = true;
            }
            zero = false;
            for(int j = 0; j < p; j++){
                scanf("%d", &out[i][j]);
                if(out[i][j] == 0)
                    zero = true;
            }
            if(!one){
                add(2*n, i, INF);
                prefix[i].push_back(2*n);
            }
            if(!zero){
                add(i+n, 2*n+1, INF);
                prefix[2*n+1].push_back(i+n);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                flag = true;
                for(int k = 0; k < p; k++){
                    if(out[i][k] + in[j][k] == 1){
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    add(i+n, j, INF);
                    prefix[j].push_back(i+n);
                }
            }
        }
        int ans = ISAP(2*n, 2*n+1);
        vector<int> v;
        for(int i = 0; i < edges.size(); i++){
            if(edges[i].flow > 0 && edges[i].from % n != edges[i].to % n && edges[i].from != 2*n && edges[i].to != 2*n+1){
                v.push_back(i);
            }
        }
        printf("%d %d\n", ans, v.size());
        for(int i = 0; i < v.size(); i++){
            Edge &e = edges[v[i]];
            printf("%d %d %d\n", (e.from)%n+1, (e.to)%n+1, e.flow);
        }
    }
    return 0;
}
