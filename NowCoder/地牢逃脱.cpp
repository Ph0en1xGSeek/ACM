#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

struct node{
    int x;
    int y;
    int cur_step;
    node(int i_x, int i_y, int step){
        x = i_x;
        y = i_y;
        cur_step = step;
    }
};

int main(){
    int n, m;
    char mp[51][51];
    int step[50][2];
    scanf("%d %d", &n , &m);
    for(int i = 0; i < n; i++){
        scanf("%s", &mp[i]);
    }
    int start_x, start_y, num_step;
    scanf("%d %d %d", &start_x, &start_y, &num_step);
    for(int i = 0; i < num_step; i++){
        scanf("%d %d", &step[i][0], &step[i][1]);
    }
    queue<node> q;
    int cur_x = start_x;
    int cur_y = start_y;
    q.push(node(cur_x, cur_y, 0));
    int result = -1;
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int cur_step = cur.cur_step;
        if(x < 0 || y < 0 || x > n ||  y > m || mp[x][y] != '.'){
            continue;
        }else{
            result = max(result, cur_step);
            mp[x][y] = '#';
            for(int i = 0; i < num_step; i++){
                q.push(node(x+step[i][0], y+step[i][1], cur_step+1));
            }
        }
    }
    for(int i = 0 ; i < n && result != -1; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '.'){
                result = -1;
                break;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
