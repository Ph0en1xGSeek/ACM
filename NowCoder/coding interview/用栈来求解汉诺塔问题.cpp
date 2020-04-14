#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

void dfs(int n, string from, string to, string mid, int state, int &cnt) {
    if(n == 1) {
        cout << "Move 1 from " << from << " to " << to << endl;
        ++cnt;
        return;
    }
    if(state == 0) {
        dfs(n-1, from, to , mid, 0, cnt);
        dfs(n-1, to, mid, from, 1, cnt);
        cout << "Move " << n << " from " << from << " to " << to << endl;
        ++cnt;
        dfs(n-1, mid, to , from, 0, cnt);
    }else if(state == 1) {
        dfs(n-1, from, mid, to, 1, cnt);
        cout << "Move " << n << " from " << from << " to " << to << endl;
        ++cnt;
        dfs(n-1, mid, from, to, 0, cnt);
        dfs(n-1, from, to, mid, 1, cnt);
    }
}

int main() {
    int n;
    while(cin >> n) {
        int cnt = 0;
        dfs(n, "left", "mid", "right", 0, cnt);
        dfs(n, "mid", "right", "left", 1, cnt);
        cout << "It will move " << cnt << " steps." << endl;
    }
    return 0;
}