class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int tmp = 1;
        vector<int> num(len, 1);
        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i-1]){
                num[i] = ++tmp;
            }else{
                tmp = 1;
                num[i] = 1;
            }
        }
        tmp = 1;
        int ans = num[len-1];
        for(int i = len-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                num[i] = max(++tmp, num[i]);
                ans += num[i];
            }else{
                tmp = 1;
                ans += num[i];
            }
        }
        return ans;
    }
};