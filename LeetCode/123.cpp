class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int b1 = -0x7fffffff, s1 = 0, b2 = -0x7fffffff, s2 = 0;
        for(int i = 0; i < prices.size(); i++){
            b1 = max(b1, -prices[i]);
            s1 = max(s1, prices[i] + b1);
            
            b2 = max(b2, s1 - prices[i]);
            s2 = max(s2, prices[i] + b2);
        }
        return s2;
    }
};