class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int right = 0;
        for(char ch: S) {
            if(ch == '(') {
                ++left;
            }else {
                if(left == 0) {
                    ++right;
                }else {
                    --left;
                }
            }
        }
        return left + right;
    }
};