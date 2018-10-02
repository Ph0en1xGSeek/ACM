#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

struct node{
    vector<int> child;
    int fa;
}tree[100];

void dfs(int cur){
    printf("(%d", cur);
    for(int i = 0; i < tree[cur].child.size(); i++)
    {
        printf(" ");
        dfs(tree[cur].child[i]);
    }
    printf(")");
}

int main()
{
    int arr[100];
    int num_child[100];
    char ch;
    int cnt = 0;
    int root;
    string line;
    priority_queue <int, vector<int>, greater<int> > q;
    while(getline(cin, line)){
        memset(num_child, 0, sizeof(num_child));
        memset(tree, 0, sizeof(tree));
        stringstream sin(line);
        while(sin >> arr[cnt]){
            num_child[arr[cnt]]++;
            cnt++;
        }
        if(cnt == 0){
            printf("(1)\n");
            continue;
        }
        root = arr[cnt-1];
        while(!q.empty())
            q.pop();
        for(int i = 1; i <= cnt+1; i++){
            if(num_child[i] == 0)
                q.push(i);
        }
        for(int i = 0; i < cnt; i++){
            int child = q.top();
            q.pop();
            int fa = arr[i];
            tree[fa].child.push_back(child);
            tree[child].fa = fa;
            num_child[fa]--;
            if(num_child[fa] == 0){
                q.push(fa);
            }
        }
        dfs(root);
        printf("\n");
        cnt = 0;
    }
    return 0;
}
