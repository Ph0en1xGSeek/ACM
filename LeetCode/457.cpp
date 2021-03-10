class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int sz = nums.size();
        int pos, pos2;
        bool sign;
        if(sz <= 1) {
            return false;
        }
        for(int i = 0; i < sz; ++i) {
            nums[i] %= sz;
        }
        for(int i = 0; i < sz; ++i) {
            if(nums[i] > -sz && nums[i] < sz && nums[i] != 0) {
                pos = i;
                sign = nums[i] > 0;
                while(nums[pos] > -sz && nums[pos] < sz && nums[pos] != 0 && (nums[pos] > 0) == sign) {
                    int step = nums[pos];
                    nums[pos] -= 2 * sz; 
                    pos = (pos + step + sz) % sz;
                }
                if(nums[pos] <= -sz) {
                    return true;
                }else {
                    pos2 = i;
                    while(pos2 != pos) {
                        nums[pos2] += 4 * sz;
                        pos2 = (pos2 + nums[pos2] - sz) % sz;
                    }
                }
            }
        }
        return false;
    }
};