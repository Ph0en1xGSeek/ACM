class Solution {
public:
    int merge(vector<int> &nums, int from, int to) {
        if(from >= to) {
            return 0;
        }
        int ret = 0;
        int mid = from + ((to - from) >> 1);
        ret += merge(nums, from, mid);
        ret += merge(nums, mid + 1, to);
        vector<int> tmp(to - from + 1);
        int pos = 0, pos1 = from, pos2 = mid + 1;
        while(pos1 <= mid && pos2 <= to) {
            if(nums[pos1] <= nums[pos2]) {
                tmp[pos++] = nums[pos1++];
            }else {
                ret += mid - pos1 + 1; 
                tmp[pos++] = nums[pos2++];
            }
        }
        while(pos1 <= mid) {
            tmp[pos++] = nums[pos1++];
        }
        while(pos2 <= to) {
            tmp[pos++] = nums[pos2++];
        }
        copy(tmp.begin(), tmp.end(), nums.begin() + from);
        return ret;
    }

    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        int ans = merge(nums, 0, size - 1);
        return ans;
    }
};