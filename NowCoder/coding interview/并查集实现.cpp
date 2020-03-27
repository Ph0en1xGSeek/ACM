#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        father.resize(n);
        for(int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    
    int getFather(int x) {
        if(father[x] == x) {
            return x;
        }
        return father[x] = getFather(father[x]);
    }
    
    void unions(int x, int y) {
        int fx = getFather(x);
        int fy = getFather(y);
        if(fx != fy) {
            father[fy] = fx;
        }
    }
    
    bool isSameSet(int x, int y) {
        int fx = getFather(x);
        int fy = getFather(y);
        if(fx != fy) {
            return false;
        }else {
            return true;
        }
    }
    
private:
    vector<int> father;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int operation, x, y;
    UnionFind unionFind(n);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &operation, &x, &y);
        if(operation == 1) {
            if(unionFind.isSameSet(x-1, y-1)) {
                printf("Yes\n");
            }else {
                printf("No\n");
            }
        }else {
            unionFind.unions(x-1, y-1);
        }
    }
    return 0;
}