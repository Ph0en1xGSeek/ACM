class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0 || k == 0) {
            return 0;
        }
        if(k > sz / 2) {
            int ans = 0;
            for(int i = 1; i < sz; ++i) {
                if(prices[i] > prices[i-1]) {
                    ans += prices[i] - prices[i-1];
                }
            }
            return ans;
        }else {
            vector<int> buy(k+1, INT_MIN);
            vector<int> sell(k+1, 0);
            for(int i = 0; i < sz; ++i) {
                for(int j = 1; j <= k; ++j) {
                    buy[j] = max(sell[j-1] - prices[i], buy[j]);
                    sell[j] = max(sell[j], buy[j] + prices[i]);
                }
            }
            return sell[k];
        }
    }
};