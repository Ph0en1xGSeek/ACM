class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> existed(26, false);
        for(int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'a'];
        }
        deque<char> dq;
        for(int i = 0; i < s.size(); ++i) {
            if(existed[s[i] - 'a']) {
                --cnt[s[i] - 'a'];
                continue;
            }
            while(!dq.empty() && s[i] < dq.back() && cnt[dq.back() - 'a'] > 0) {
                existed[dq.back() - 'a'] = false;
                dq.pop_back();
            }
            dq.push_back(s[i]);
            --cnt[s[i] - 'a'];
            existed[s[i] - 'a'] = true;
        }
        string ret = "";
        for(int i = 0; i < dq.size(); ++i) {
            ret += dq[i];
        }
        return ret;
    }
};