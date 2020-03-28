#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void dfs(int num, bool reverse) {
    if(num == 0) {
        return;
    }
    if(!reverse) {
        dfs(num - 1, reverse);
        cout << "down" << endl;
        dfs(num - 1, !reverse);
    }else {
        dfs(num - 1, !reverse);
        cout << "up" << endl;
        dfs(num - 1, reverse);
    }

}

int main() {
    int num;
    while(cin >> num) {
        dfs(num, false);
    }
    return 0;
}