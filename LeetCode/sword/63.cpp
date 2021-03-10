class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0) {
            return 0;
        }
        int ans = 0;
        int curMin = prices[0];
        for(int i = 1; i < size; ++i) {
            ans = max(prices[i] - curMin, ans);
            curMin = min(curMin, prices[i]);
        }
        return ans;
    }
};