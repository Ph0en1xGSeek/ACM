class Solution {
public:
    int dfs(int from, int to, vector<int>& mem){
        int ret = 0;
        if(from >= to){
            ret = 1;
        }else if(mem[to - from] > 0){
            ret = mem[to - from];
        }else{
            for(int i = from; i <= to; i++){
                int tmp = dfs(from, i-1, mem);
                tmp *= dfs(i+1, to, mem);
                ret += tmp;
            }
            mem[to-from] = ret;
        }
        return ret;
    }
    
    int numTrees(int n) {
        if(n == 0)
            return 1;
        vector<int> mem(n, -1);
        int ret = dfs(1, n, mem);
        return ret;
    }
};