class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<int> mem;
        bool res = dfs(s, dict, 0, mem);
        return res;
    }
    
    bool dfs(string &s, unordered_set<string> &dict, int start, unordered_set<int> &mem) {
        if(mem.find(start) != mem.end()) {
            return false;
        }
        int sz = s.size();
        if(start == sz) {
            return true;
        }
        for(int i = start+1; i <= sz; ++i) {
            if(dict.find(s.substr(start, i - start)) != dict.end() && dfs(s, dict, i, mem)) {
                return true;
            }
        }
        mem.insert(start);
        return false;
    }
};