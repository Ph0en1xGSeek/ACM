class Solution {
public:
    bool isUpperCase(char c) {
        if(c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }
    bool detectCapitalUse(string word) {
        int size = word.size();
        if(size <= 1) {
            return true;
        }
        if(!isUpperCase(word[0])) {
            for(int i = 0; i < size; ++i) {
                if(isUpperCase(word[i])) {
                    return false;
                }
            }
            return true;
        }else {
            if(isUpperCase(word[1])) {
                for(int i = 1; i < size; ++i) {
                    if(!isUpperCase(word[i])) {
                        return false;
                    }
                }
                return true;
            }else {
                for(int i = 1; i < size; ++i) {
                    if(isUpperCase(word[i])) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
};