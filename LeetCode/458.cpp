class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest / minutesToDie + 1;
        if(buckets <= 1) {
            return 0;
        }else if(t == 1) {
            return -1;
        }
        int x = 1;
        int tmp = t;
        while(1) {
            if(tmp >= buckets) {
                break;
            }
            tmp *= t;
            ++x;
        }
        return x;
    }
};