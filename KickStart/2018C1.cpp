#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 1005

using namespace std;

vector<vector<int>> adj(MAXN);
bool isCircle[MAXN];
int dis[MAXN];
bool vis[MAXN];

int search_circle(int node, int from) {
    if(vis[node]) {
        isCircle[node] = true;
        return node;
    }
    vis[node] = true;
    int sz = adj[node].size();
    for(int i = 0; i < sz; ++i) {
        if(adj[node][i] == from) {
            continue;
        }
        int ret = search_circle(adj[node][i], node);
        if(ret > 0) {
            isCircle[node] = true;
            if(ret == node) {
                return -1;
            }else {
                return ret;
            }
        }else if(ret < 0) {
            return -1;
        }
    }
    return 0;
}

void count_dis(int node, int from, int depth) {
    if(isCircle[node] == true && depth != 0) {
        return;
    }
    dis[node] = depth;
    int sz = adj[node].size();
    for(int i = 0; i < sz; ++i) {
        if(adj[node][i] == from) {
            continue;
        }
        count_dis(adj[node][i], node, depth + 1);
    }
}

int main() {
    int T, n;
    int x, y;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for(int i = 1; i <= 1000; ++i) {
            adj[i].clear();
        }
        memset(isCircle, false, sizeof(isCircle));
        memset(dis, 0, sizeof(dis));
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        search_circle(1, -1);
        for(int i = 1; i <= n; ++i) {
            if(isCircle[i]) {
                count_dis(i, -1, 0);
            }
        }
        printf("Case #%d:", t);
        for(int i = 1; i <= n; ++i) {
            printf(" %d", dis[i]);
        }
        printf("\n");
    }
    return 0;
}