class Solution {
public:
    bool isMatch(string s, string p) {
        size_s = s.size();
        size_p = p.size();
        return match(s, 0, p, 0);
    }

    bool match(string &s, int pos_s, string &p, int pos_p) {
        if(pos_p == size_p && pos_s == size_s) {
            return true;
        }else if(pos_p == size_p && pos_s < size_s) {
            return false;
        }else if(pos_p < size_p - 1 && p[pos_p + 1] == '*') {
            if(pos_s < size_s && (s[pos_s] == p[pos_p] || p[pos_p] == '.')) {
                return match(s, pos_s, p, pos_p + 2) || match(s, pos_s+1, p, pos_p);
            }else {
                return match(s, pos_s, p, pos_p + 2);
            }
        }else {
            if(pos_s < size_s && (s[pos_s] == p[pos_p] || p[pos_p] == '.')) {
                return match(s, pos_s + 1, p, pos_p + 1);
            }else {
                return false;
            }
        }
    }

private:
    int size_s;
    int size_p;
};