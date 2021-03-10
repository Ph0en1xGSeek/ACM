class Solution {
public:
    string dfs(string &s, int &pos, int sz) {
        string ret = "";
        int ori_pos = pos;
        while(pos < sz && s[pos] != ']') {
            if(s[pos] >= '0' && s[pos] <= '9') {
                ret += s.substr(ori_pos, pos - ori_pos);
                int num = 0;
                while(s[pos] >= '0' && s[pos] <= '9') {
                    num = num * 10 + (s[pos] - '0');
                    ++pos;
                }
                ++pos;
                string c_str = dfs(s, pos, sz);
                for(int i = 0; i < num; ++i) {
                    ret += c_str;
                }
                ori_pos = ++pos;
            }else {
                ++pos;
            }
        }
        ret += s.substr(ori_pos, pos - ori_pos);
        return ret;
    }
    
    string decodeString(string s) {
        int pos = 0;
        int sz = s.size();
        return dfs(s, pos, sz);
    }
};