class Solution {
public:
	int maxProfit(vector<int> &prices, int fee) {
		int size = prices.size();
		if(size == 0) {
			return 0;
		}
		int buy, sell;
		buy = -prices[0];
		sell = 0;
		for(int i = 1; i < size; ++i) {
			buy = max(buy, sell - prices[i-1]);
			sell = max(sell, buy + prices[i] - fee);
		}
		return sell;
	}
};