class Solution {
public:
    int merge(vector<int> &nums, int from, int to) {
        if(to <= from) {
            return 0;
        }
        int mid = from + ((to - from) >> 1);
        int ret = merge(nums, from, mid) + merge(nums, mid + 1, to);
        int i = from, j = mid + 1;
        while(i <= mid && j <= to) {
            if(nums[i] / 2 > nums[j] || (nums[i] / 2 == nums[j] && nums[i] % 2 == 1)) {
                ret += mid + 1 - i;
                ++j;
            }else {
                ++i;
            }
        }
        i = from, j = mid + 1;
        vector<int> tmp(to - from + 1);
        int pos = 0;
        while(i <= mid && j <= to) {
            if(nums[i] < nums[j]) {
                tmp[pos++] = nums[i++];
            }else {
                tmp[pos++] = nums[j++];
            }
        }
        while(i <= mid) {
            tmp[pos++] = nums[i++];
        }
        while(j <= to) {
            tmp[pos++] = nums[j++];
        }
        copy(tmp.begin(), tmp.end(), nums.begin() + from);
        return ret;
    }
    
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }
};