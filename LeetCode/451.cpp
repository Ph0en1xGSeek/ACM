class Solution {
public:
    string frequencySort(string s) {
        int sz = s.size();
        if(sz == 0) {
            return "";
        }
        unordered_map<char, int> freq;
        unordered_map<int, unordered_set<char>> mp;
        string res = "";
        for(int i = 0; i < sz; ++i) {
            ++freq[s[i]];
        }
        for(int i = 0; i < 128; ++i) {
            for(auto fq: freq) {
                mp[fq.second].insert(fq.first);
            }
        }
        for(int i = sz; i > 0; --i) {
            if(mp.find(i) != mp.end()) {
                for(char c: mp[i]) {
                    res += string(i, c);
                }
            }
        }
        return res;
    }
};