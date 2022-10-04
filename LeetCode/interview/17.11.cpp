class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> mp;
        int size = words.size();
        for(int i = 0; i < size; ++i) {
            mp[words[i]].push_back(i);
        }
        int ans = INT_MAX;
        int size1 = mp[word1].size();
        int size2 = mp[word2].size();
        int pos1 = 0;
        int pos2 = 0;
        while(pos1 < size1 && pos2 < size2) {
            if(mp[word1][pos1] < mp[word2][pos2]) {
                ans = min(ans, mp[word2][pos2] - mp[word1][pos1]);
                ++pos1;
            }else {
                ans = min(ans, mp[word1][pos1] - mp[word2][pos2]);
                ++pos2;
            }
        }
        return ans;
    }
};