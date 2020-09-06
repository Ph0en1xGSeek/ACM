class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        if(size == 0) {
            return s;
        }
        int pre = 0;
        for(int i =  0; i < size; ++i) {
            if(s[i] == ' ') {
                reverse(s.begin() + pre, s.begin() + i);
                pre = i + 1;
            }
        }
        reverse(s.begin() + pre, s.begin() + size);
        return s;
    }
};