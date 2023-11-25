class Solution {
public:

    int partition(vector<int> &nums, int left, int right) {
        while (left < right) {
            while (left < right && nums[left] <= nums[right]) {
                --right;
            }
            swap(nums[left], nums[right]);
            while (left < right && nums[left] <= nums[right]) {
                ++left;
            }
            swap(nums[left], nums[right]);
        }
        return left;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        k = size - k;
        int left = 0, right = size - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k) {
                return nums[pos];
            } else if (pos < k) {
                left = pos + 1;
            } else {
                right = pos - 1;
            }
        }
        return 0;
    }
};