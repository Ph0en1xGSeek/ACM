class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(dict.find(end) == dict.end()) {
            return 0;
        }
        int sz = start.size();
        queue<string> q;
        unordered_set<string> visited;
        int len = 0;
        q.push(start);
        while(!q.empty()) {
            int layer_cnt = q.size();
            ++len;
            for(int i = 0; i < layer_cnt; ++i) {
                string cur = q.front();
                q.pop();
                if(cur == end) {
                    return len;
                }
                for(int j = 0; j < sz; ++j) {
                    string newcur = cur;
                    for(char c = 'a'; c <= 'z'; ++c) {
                        newcur[j] = c;
                        if(visited.find(newcur) == visited.end() && dict.find(newcur) != dict.end()) {
                            visited.insert(newcur);
                            q.push(newcur);
                        }
                    }
                }
            }
        }
        return 0;
    }
};