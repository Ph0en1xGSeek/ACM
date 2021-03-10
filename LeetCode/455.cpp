class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sz_g = g.size();
        int sz_s = s.size();
        if(sz_g == 0 || sz_s == 0) {
            return 0;
        }
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int pos_g = 0;
        int pos_s = 0;
        int res = 0;
        while(pos_g < sz_g && pos_s < sz_s) {
            if(g[pos_g] > s[pos_s]) {
                ++pos_g;
            }else {
                ++pos_s;
                ++pos_g;
                ++res;
            }
        }
        return res;
    }
};