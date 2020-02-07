class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res;
        if(sz <= 1) {
            return res;
        }
        int pos;
        for(int i = 0; i < sz; ++i) {
            if(nums[i] <= sz) {
                pos = i;
                int tmp = nums[i] - 1;
                nums[i] -= sz;
                while(1 <= nums[tmp] && nums[tmp] <= sz) {
                    pos = tmp;
                    tmp = nums[pos] - 1;
                    nums[pos] += sz;
                }
                if(nums[tmp] < 1) {
                    nums[tmp] = nums[tmp] + sz + sz;
                }else if(nums[tmp] > sz) {
                    res.push_back(tmp+1);
                }
            }
        }
        return res;
    }
};