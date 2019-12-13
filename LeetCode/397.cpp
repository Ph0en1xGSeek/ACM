class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        long long ln = n;
        while(ln > 1) {
            if(ln & 1) {
                if(ln % 4 == 3 && ln != 3) {
                    ++ln;
                }else {
                    --ln;
                }
            }else {
                ln >>= 1;
            }
            ++cnt;
        }
        return cnt;
    }
        
};