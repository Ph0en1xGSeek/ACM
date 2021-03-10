class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int sz = b.size();
        int pos = 0;
        a %= 1337;
        if(sz == 1 && b[0] == 0) {
            return 1;
        }
        if(a == 0) {
            return 0;
        }
        int ans = 1;
        while(pos < sz) {
            if((b[sz-1] & 1) == 1) {
                ans = (ans * a) % 1337;
            }
            a = (a * a) % 1337;
            int tmp = 0;
            for(int i = pos; i < sz; ++i) {
                if(tmp == 1) {
                    b[i] += 10;
                }
                tmp = b[i] & 1;
                b[i] /= 2;
            }
            while(pos < sz && b[pos] == 0) {
                ++pos;
            }
        }
        return ans;
    }
};