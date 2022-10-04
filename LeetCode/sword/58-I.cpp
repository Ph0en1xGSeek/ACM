class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        if (size == 0) {
            return s;
        }
        int pre = size;
        string ans = "";
        bool first = true;
        for (int i = size - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (i < pre - 1) {
                    if (first) {
                        first = false;
                    } else {
                        ans += ' ';
                    }
                    ans += s.substr(i + 1, pre - i - 1);
                }
                pre = i;
            }
        }
        if (pre >= 1) {
            if (!first) {
                ans += ' ';
            }
            ans += s.substr(0, pre);
        }
        return ans;
    }
};