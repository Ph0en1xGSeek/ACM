class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        int k = 1;
        vector<int> ugly_num;
        ugly_num.push_back(1);
        vector<int> index(sz, 0);
        while(k < n) {
            int mi = 0x7fffffff;
            for(int i = 0; i < sz; ++i) {
                if(ugly_num[index[i]] * primes[i] < mi)
                    mi = ugly_num[index[i]] * primes[i];
            }
            ugly_num.push_back(mi);
            for(int i = 0; i < sz; ++i) {
                if(ugly_num[index[i]] * primes[i] == mi) {
                    ++index[i];
                }
            }
            ++k;
        }
        return ugly_num[n-1];
    }
};