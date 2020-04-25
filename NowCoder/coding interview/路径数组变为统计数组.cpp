#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int num, tmp;
    cin >> num;
    vector<vector<int>> arr(num);
    vector<bool> visit(num, false);
    int cap;
    for(int i = 0 ; i < num; ++i) {
        cin >> tmp;
        arr[tmp].push_back(i);
        if(tmp == i) {
            cap = i;
        }
    }
    vector<int> ans(num, 0);
    int cnt = 0;
    queue<int> q;
    q.push(cap);
    visit[cap] = true;
    while(!q.empty()) {
        int size = q.size();
        ans[cnt++] = size;
        for(int i = 0; i < size; ++i) {
            int cur = q.front();
            q.pop();
            int adj_size = arr[cur].size();
            for(int j = 0; j < adj_size; ++j) {
                if(!visit[arr[cur][j]]) {
                    visit[arr[cur][j]] = true;
                    q.push(arr[cur][j]);
                }
            }
        }
    }
    for(int i = 0; i < num; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}