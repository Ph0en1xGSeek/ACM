class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) {
            return x;
        }
        int left = 1;
        int right = x / 2;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(x / mid < mid) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        } 
        return left - 1;
    }
};