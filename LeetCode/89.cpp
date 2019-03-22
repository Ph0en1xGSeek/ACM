class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1<<n);
        result[0] = 0;
        if(n == 0){
            return result;
        }
        result[1] = 1;
        for(int i = 2; i <= n; i++){
            copy(result.begin(), result.begin() + (1 << (i-1)), result.begin() + (1 << (i-1)));
            reverse(result.begin() + (1 << (i-1)), result.begin() + (1 << (i)));
            for(int j = (1 << (i-1)); j < (1 << (i)); j++){
                result[j] ^= (1 <<(i-1));
            }
        }
        return result;
    }
};