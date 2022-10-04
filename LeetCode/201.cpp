class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int span = n - m;
        int i = 0;
        int ans = 0;
        while(i < 32 && (1<<i) <= n){
            if(span >= (1<<i)){
                
            }else{
                ans += ((1<<i) & m) & ((1<<i) & n);
            }
            i++;
        }
        return ans;
    }
};