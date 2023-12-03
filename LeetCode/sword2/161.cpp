class Solution {
public:
    int maxSales(vector<int>& sales) {
        int size = sales.size();
        int sum = 0;
        int ans = INT_MIN;
        for (auto sale : sales) {
            sum += sale;
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};