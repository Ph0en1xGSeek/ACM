class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &num, int pos) {
        int sz = num.size();
        if(pos == sz) {
            ans.push_back(num);
        }
        for(int i = pos; i < sz; ++i) {
            swap(num[i], num[pos]);
            dfs(ans, num, pos+1);
            swap(num[i], num[pos]);
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        dfs(ans, num, 0);
        return ans;
    }
};