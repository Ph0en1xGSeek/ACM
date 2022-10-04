class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int size = strs.size();
        for(int i = 0; i < size; ++i) {
            int str_size = strs[i].size();
            int arr[26] = {0};
            for(int j = 0; j < str_size; ++j) {
                ++arr[strs[i][j] - 'a'];
            }
            ostringstream ss;
            for(int j = 0; j < 26; ++j) {
                ss << arr[j] << ".";
            }
            string key = ss.str();
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
            ans.push_back(iter->second);
        }
        return ans;
    }
};