class Solution {
public:


    static int fun1(int n) {
        int (*funArr[2])(int) = {Solution::fun0, Solution::fun1};
        return n + funArr[!!n](n-1);
    }

    static int fun0(int n) {
        return 0;
    }


    int sumNums(int n) {
        return fun1(n);
    }
};