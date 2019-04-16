#include <iostream>
#include <stdio.h>
#include <queue>
#include <unordered_set>

using namespace std;

int main(){
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int num;
    scanf("%d", &num);
    vector<int> x(num, 0);
    for(int i = 0; i < num; i++){
        scanf("%d", &x[i]);
    }
    int tmp;
    unordered_set<int> trap;
    for(int i = 0; i < num; i++){
        scanf("%d", &tmp);
        trap.insert(x[i] * 1000 + tmp);
    }
    int step = -1;
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push(make_pair(1, 1));
    bool found = false;
    while(!q.empty() && !found){
        step++;
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            pair<int, int> cur = q.front();
            q.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            if(trap.count(cur_x * 1000 + cur_y) != 0){
                found = true;
                break;
            }
            for(int j = 0; j < 4; j++){
                int next_x = cur_x + dir[j][0];
                int next_y = cur_y + dir[j][1];
                if(next_x > 0 && next_y > 0 && next_x <= 1000 && next_y <= 1000){
                    if(visited.count(next_x *1000 + next_y) == 0){
                        visited.insert(next_x * 1000 + next_y);
                        pair<int, int> nex = make_pair(next_x, next_y);
                        q.push(nex);
                    }
                }
            }
        }
    }
    printf("%d\n", step);
    return 0;
}
