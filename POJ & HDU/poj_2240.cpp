#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
#define M 35
#define INF 80000000

using namespace std;

double arr[M][M];
bool isInqueue[M];
int numInqueue[M];
int num, numedge;
double dis[M];


bool spfa(){
    memset(numInqueue, 0, sizeof(numInqueue));
    memset(isInqueue, 0, sizeof(isInqueue));
    queue<int> q;
    for(int i = 1; i <= num; i++){
        dis[i] = INF;
        q.push(i);
        isInqueue[i] = true;
        numInqueue[i]++;
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        isInqueue[cur] = false;
        for(int i = 1; i <= num; i++){
            if(arr[cur][i] > 0){
                if(dis[i] < dis[cur]*arr[cur][i]){
                    dis[i] = dis[cur] * arr[cur][i];
                    if(!isInqueue[i]){
                        q.push(i);
                        isInqueue[i] = true;
                        numInqueue[i] ++;
                        if(numInqueue[i] >= num)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int ca = 1;
    while(scanf("%d", &num) && num != 0){
        memset(arr, 0 , sizeof(arr));
        map<string, int> m;
        string name, c1, c2;
        double rate;
        for(int i = 1; i <= num; i++){
            cin >> name;
            m[name] = i;
        }
        scanf("%d", &numedge);
        for(int i = 1; i <= numedge; i++){
            cin >> c1 >> rate >> c2;
            arr[m[c1]][m[c2]] = rate;
        }
        bool flag = spfa();
        if(flag)
            printf("Case %d: Yes\n", ca++);
        else
            printf("Case %d: No\n", ca++);
    }
    return 0;
}
