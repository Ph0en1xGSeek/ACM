class Solution {
public:
    bool isPalindrome(string &s, int from, int to) {
        while(from < to) {
            if(s[from] != s[to]) {
                return false;
            }
            ++from;
            --to;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        bool removed = false;
        int sz = s.size();
        int i = 0, j = sz - 1;
        while(i < j) {
            if(s[i] == s[j]) {
                ++i;
                --j;
            }else if(!removed) {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};