class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            while (left < right && !isPlainChar(s[left])) {
                ++left;
            }
            while (left < right && !isPlainChar(s[right])) {
                --right;
            }
            if (left < right) {
                if (isSame(s[left], s[right])) {
                    ++left;
                    --right;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isPlainChar(char ch) {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z');
    }

    bool isSame(char a, char b) {
        if (a == b) {
            return true;
        }
        if (a >= 'a' && a <= 'z' && a - 'a' + 'A' == b) {
            return true;
        }
        if (a >= 'A' && a <= 'Z' && a - 'A' + 'a' == b) {
            return true;
        }
        return false;
    }
};