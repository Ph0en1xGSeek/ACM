class Solution {
public:
    bool validPalindrome(string s) {
        int size = s.size();
        int left = 0;
        int right = size - 1;
        bool second = false;
        
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                if (isValid(s, left, right - 1) || isValid(s, left + 1, right)) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(string &s, int left, int right) {
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
};