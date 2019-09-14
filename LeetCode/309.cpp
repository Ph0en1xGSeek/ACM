class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0) {
            return 0;
        }
        vector<int> s(sz, -0x7fffffff);
        vector<int> prev_s;
        int b = -0x7fffffff;
        for(int i = 0; i < sz; ++i) {
            b = max(b, -prices[i]);
            if(i > 0)
                s[i] = s[i-1];
            s[i] = max(s[i], prices[i] + b);
        }
        for(int j = 2; j < sz; j += 2) {
            b = -0x7fffffff;
            prev_s = s;
            for(int i = j; i < sz; ++i) {
                b = max(b, prev_s[i-2] - prices[i]);
                s[i] = max(s[i], s[i-1]);
                s[i] = max(s[i], b + prices[i]);
            }
        }
        return s[sz-1];
    }
};