class Solution {
public:
    int findKthNumber(int n, int k) {
        long long prefix = 1;
        k--;
        while(k > 0){
            long long from = prefix;
            long long to = prefix + 1;
            long long step = 0;
            while(from <= n){
                step += min((long long)n+1, to) - from;
                from *= 10;
                to *= 10;
            }
            if(step <= k){
                k -= step;
                prefix++;
            }else{
                prefix *= 10;
                k--;
            }
        }
        return prefix;
    }
};