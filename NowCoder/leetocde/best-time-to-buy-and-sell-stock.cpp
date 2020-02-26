class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sz = prices.size();
        if(sz == 0) {
            return 0;
        }
        int low = prices[0];
        int ans = 0;
        for(int i = 1; i < sz; ++i) {
            if(prices[i] < low) {
                low = prices[i];
            }else {
                ans = max(prices[i] - low, ans);
            }
        }
        return ans;
    }
};