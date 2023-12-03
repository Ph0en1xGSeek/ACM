class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int countTarget(vector<int>& scores, int target) {
        int size = scores.size();
        if (size == 0) {
            return 0;
        }
        int lower = lower_bound(scores, target);
        int upper = upper_bound(scores, target);
        return upper - lower;
    }
};