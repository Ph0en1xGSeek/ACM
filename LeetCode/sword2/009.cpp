class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int ans = 0;
        if (k <= 1) {
            return 0;
        }
        int i = 0;
        int j = 1;
        int sum = nums[0];
        while(true) {
            while (sum < k) {
                ans += (j - i);
                if (j < size) {
                    sum *= nums[j++];
                } else {
                    break;
                }
            }
            if (j >= size && sum < k) {
                break;
            }
            while ( i < j && sum >= k) {
                sum /= nums[i++];
            }
        }
        return ans;
    }
};