class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sz = array.size();
        if(sz == 0) {
            return 0;
        }
        int mx = INT_MIN;
        int sum = 0;
        for(int i = 0; i < sz; ++i) {
            if(sum < 0) {
                sum = 0;
            }
            sum += array[i];
            mx = max(mx, sum);
        }
        return mx;
    }
};