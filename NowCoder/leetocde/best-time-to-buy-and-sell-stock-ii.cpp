class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sz = prices.size();
        if(sz == 0) {
            return 0;
        }
        int i = 0;
        int ans = 0;
        while(i < sz) {
            int j = i;
            while(j+1 < sz && prices[j+1] >= prices[j]) {
                ++j;
            }
            ans += prices[j] - prices[i];
            i = j+1;
        }
        return ans;
    }
};