// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int tmp;
        while((tmp = rand49()) > 40);
        return tmp % 10 + 1;
    }
    
    int rand49() {
        int r1 = rand7();
        int r2 = rand7() - 1;
        return r2 * 7 + r1;
    }
};