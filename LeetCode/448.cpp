class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res;
        if(sz == 0) {
            return res;
        }
        int pos;
        for(int i = 0; i < sz; ++i) {
            pos = i;
            int tmp = nums[pos];
            while(1 <= tmp && tmp <= sz) {
                pos = tmp - 1;
                tmp = nums[pos];
                nums[pos] += sz;
            }
        }
        
        for(int i = 0; i < sz; ++i) {
            if(1 <= nums[i] && nums[i] <= sz) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};