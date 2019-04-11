class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        int cnt = 0;
        vector<bool> isPrime(n, true);
        for(int i = 2; i < n; i++){
            if(isPrime[i]){
                cnt++;
                for(int j = 2; j * i < n; j++){
                    isPrime[i*j] = false;
                }
            }
        }
        return cnt;
    }
};