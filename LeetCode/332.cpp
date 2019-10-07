class Solution {
public:
    void dfs(map<string, multiset<string>> &mp, string cur, vector<string> &result) {
        while(mp[cur].size()) {
            string nex = *(mp[cur].begin());
            mp[cur].erase(mp[cur].begin());
            dfs(mp, nex, result);
        }
        result.push_back(cur);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> mp;
        for(auto item: tickets) {
            mp[item[0]].insert(item[1]);
        }
        string cur = "JFK";
        vector<string> result;
        dfs(mp, cur, result);
        reverse(result.begin(), result.end());
        return result;
    }
};