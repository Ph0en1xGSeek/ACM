class Solution {
public:
    bool cmp(string &s, string &d) {
        int s_size = s.size();
        int d_size = d.size();
        int pos1 = 0, pos2 = 0;
        while(pos1 < s_size && pos2 < d_size) {
            if(s[pos1] != d[pos2]) {
                ++pos1;
            }else {
                ++pos1;
                ++pos2;
            }
        }
        if(pos2 < d_size) {
            return false;
        }
        return true;
    }

    string findLongestWord(string s, vector<string>& d) {
        int d_size = d.size();
        string ans = "";
        int cur_len = 0;
        for(int i = 0; i < d_size; ++i) {
            if(cmp(s, d[i])) {
                if(d[i].size() > cur_len) {
                    cur_len = d[i].size();
                    ans = d[i];
                }else if(d[i].size() == cur_len) {
                    if(d[i] < ans) {
                        ans = d[i];
                    }
                }
            }
        }
        return ans;
    } 
};