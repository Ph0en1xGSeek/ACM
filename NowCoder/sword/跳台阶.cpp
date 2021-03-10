class Solution {
public:
    int jumpFloor(int number) {
        int ans = 1;
        if(number <= 2) {
            return number;
        }
        int a = 2, b = 1, tmp;
        for(int i = 3; i <= number; ++i) {
            tmp = a;
            a += b;
            b = tmp;
        }
        return a;
    }
};