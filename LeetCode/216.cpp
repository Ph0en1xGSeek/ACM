class Solution {
public:
    
    void dfs(vector<vector<int>> &res, vector<int> &ans, int deep, int n, int from){
        if(deep == 0 && n == 0){
            res.push_back(ans);
            return;
        }
        if((deep == 0 && n != 0) || n < 0){
            return;
        }
        for(int i = from; i <= 9; i++){
            ans.push_back(i);
            dfs(res, ans, deep-1, n-i, i+1);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        dfs(res, ans, k, n, 1);
        return res;
    }
};
