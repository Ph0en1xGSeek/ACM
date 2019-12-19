class Solution {
public:
    string toHex(int num) {
        if(num == 0) {
            return "0";
        }
        string ret;
        while(num) {
            int rem = num & 15;
            if(rem < 10) {
                ret += (rem + '0');
            }else {
                ret += (rem - 10 + 'a');
            }
            num >>= 4;
            if(num < 0) {
                num &= 0x0fffffff;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};