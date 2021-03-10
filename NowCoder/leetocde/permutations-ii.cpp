class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &num, int pos) {
        int sz = num.size();
        if(pos == sz) {
            ans.push_back(num);
        }
        unordered_set<int> st;
        for(int i = pos; i < sz; ++i) {
            if(st.find(num[i]) == st.end()) {
                st.insert(num[i]);
                swap(num[i], num[pos]);
                dfs(ans, num, pos+1);
                swap(num[i], num[pos]);
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> ans;
        sort(num.begin(), num.end());
        dfs(ans, num, 0);
        return ans;
    }
};