class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int left = 0, right = nums.back() - nums[0];
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            int start = 0;
            int cnt = 0;
            for(int i = 1; i < size; ++i) {
                while(start < i && nums[i] - nums[start] > mid) {
                    ++start;
                }
                cnt += i - start;
            }
            if(cnt < k) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }
};