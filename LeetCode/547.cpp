class Solution {
public:
    int find(int x) {
        if(father[x] == -1) {
            return x;
        }else {
            return father[x] = find(father[x]);
        }
    }
    
    void unions(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if(fa != fb) {
            father[fa] = fb;
            --cnt;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int sz = M.size();
        cnt = sz;
        if(sz == 0) {
            return 0;
        }
        father.assign(sz, -1);
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < i; ++j) {
                if(M[i][j]) {
                    unions(i, j);
                }
            }
        }
        return cnt;
    }
private:
    vector<int> father;
    int cnt;
};