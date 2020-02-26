class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int buy = INT_MIN, pre_buy = INT_MIN, sell = 0, pre_sell = 0;
        for(int i = 0; i < sz; ++i) {
            buy = max(buy, pre_sell - prices[i]);
            pre_sell = sell;
            sell = max(sell, buy + prices[i]);
        }
        return sell;
    }
};