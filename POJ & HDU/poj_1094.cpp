#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

bool arr[26][26];
int n, m;
int degree[26];
char ans[30];

int topoSort(){
    int ret = 1;
    int pos = 0;
    int tmpDegree[26];
    memcpy(tmpDegree, degree, sizeof(tmpDegree));
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(degree[i] == 0)
            q.push(i);
    while(!q.empty()){
        if(q.size() > 1)
            ret = 0;
        int cur = q.front();
        q.pop();
        ans[pos++] = cur + 'A';
        for(int i = 0; i < n; i++){
            if(arr[cur][i]){
                tmpDegree[i]--;
                if(tmpDegree[i] == 0)
                    q.push(i);
            }
        }
    }
    if(pos < n){
        return -1;
    }
    ans[pos] = '\0';
    return ret;
}

int main(){
    char ch[4];
    bool flag = false;
    while(~scanf("%d%d", &n, &m) && n != 0){
        memset(arr, 0, sizeof(arr));
        memset(degree, 0, sizeof(degree));
        flag = false;
        for(int i = 0; i < m; i++){
            scanf("%s", ch);
            arr[ch[0]-'A'][ch[2]-'A'] = true;
            if(flag)    continue;
            degree[ch[2]-'A']++;
            int topo = topoSort();
            if(topo == 1){
                flag = true;
                printf("Sorted sequence determined after %d relations: %s.\n", i+1, ans);
            }else if(topo == -1){
                flag = true;
                printf("Inconsistency found after %d relations.\n", i+1);
            }
        }
        if(!flag)
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
