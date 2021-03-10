class Solution {
public:
    
    bool isalpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    
    bool isdigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    
    char lower(char ch) {
        if(ch >= 'A' && ch <= 'Z') {
            return ch - ('A' - 'a');
        }
        return ch;
    }
    
    bool isPalindrome(string s) {
        int sz = s.size();
        if(sz == 0) {
            return true;
        }
        int i = 0, j = sz - 1;
        while(i <= j) {
            while(i <= j && !(isdigit(s[i]) || isalpha(s[i])))
                ++i;
            while(i <= j && !(isdigit(s[j]) || isalpha(s[j])))
                --j;
            if(i > j) {
                break;
            }
            if(lower(s[i]) != lower(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};