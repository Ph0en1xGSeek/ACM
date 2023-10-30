class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (unordered_map<string, vector<string>>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
            ans.push_back(iter -> second);
        }
        return ans;
    }
};