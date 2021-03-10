class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        char num[33];
        for(int i = 1; i <= n; ++i) {
            if(i % 3 == 0 || i % 5 == 0) {
                ret.push_back("");
                if(i % 3 == 0) {
                    ret[i-1] += "Fizz";
                }
                if(i % 5 == 0){
                    ret[i-1] += "Buzz";
                }
                continue;
            }
            int tmp = i;
            int pos = 0;
            while(tmp) {
                num[pos++] = '0' + tmp % 10;
                tmp /= 10;
            }
            reverse(begin(num), begin(num)+pos);
            num[pos++] = '\0';
            ret.push_back(string(num));
        }
        return ret;
    }
};