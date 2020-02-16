class Solution {
public:
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[l];
        while(l < r) {
            while(l < r && nums[r] >= pivot) {
                --r;
            }
            nums[l] = nums[r];
            while(l < r && nums[l] <= pivot) {
                ++l;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
    
    int minMoves2(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 1) {
            return 0;
        }
        int l = 0, r = sz-1;
        int target = sz / 2;
        while(l <= r) {
            int index = partition(nums, l, r);
            if(index == target) {
                break;
            }else if(index < target) {
                l = index + 1;
            }else if(index > target) {
                r = index - 1;
            }
        }
        int mid = nums[target];
        long long cnt = 0;
        for(int i = 0; i < sz; ++i) {
            if(nums[i] < mid) {
                cnt += mid - nums[i];
            }else {
                cnt += nums[i] - mid;
            }
        }
        return cnt;
    }
};