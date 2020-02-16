class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis = x ^ y;
        int pos = 1;
        int cnt = 0;
        while(pos > 0) {
            if(pos & dis) {
                ++cnt;
            }
            pos <<= 1;
        }
        return cnt;
    }
};