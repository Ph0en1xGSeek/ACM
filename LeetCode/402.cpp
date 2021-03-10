class Solution {
public:
    string removeKdigits(string num, int k) {
        char str[10004];
        int pos = 0;
        int sz = num.size();
        if(sz == k) {
            return "0";
        }
        for(int i = 0; i < sz; ++i) {
            while(pos > 0 && num[i] < str[pos-1] && k > 0) {
                --pos;
                --k;
            }
            str[pos++] = num[i];
        }
        pos -= k;
        str[pos++] = '\0';
        int from = 0;
        while(from < pos && str[from] == '0') {
            ++from;
        }
        string ret;
        if(from == pos-1) {
            ret = "0";
        }else {
            ret = string(str).substr(from, pos - from);
        }
        return ret;
    }
};