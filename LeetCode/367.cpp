class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 0; i <= 46340 && i * i <= num; ++i) {
            if(i * i == num) {
                return true;
            }
        }
        return false;
    }
};