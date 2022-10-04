class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int sz = start.size();
        int sz_end = end.size();
        if(sz != sz_end) {
            return -1;
        }
        unordered_set<string> st;
        for(string s: bank) {
            if(int(s.size()) == sz)
                st.insert(s);
        }
        if(st.find(end) == st.end()) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push({start, 0});
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            string cur = f.first;
            int cur_step = f.second;
            for(int i = 0; i < sz; ++i) {
                for(int j = 0; j < 4; ++j) {
                    if(cur[i] != gene[j]) {
                        string tmp = cur.substr(0, i) + gene[j] + cur.substr(i+1, sz-i-1);
                        if(st.find(tmp) != st.end()) {
                            if(tmp == end) {
                                return cur_step + 1;
                            }
                            st.erase(st.find(tmp));
                            q.push({tmp, cur_step + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
private:
    char gene[4] = {'A', 'C', 'G', 'T'};
};