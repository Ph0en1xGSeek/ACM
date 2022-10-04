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


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res;
        if(sz <= 1) {
            return res;
        }
        for(int i = 0; i < sz; ++i) {
            int idx = nums[i];
            if(idx > sz) {
                idx -= sz;
            }
            if(nums[idx - 1] > sz) {
                res.push_back(idx);
            }else {
                nums[idx - 1] += sz;
            }
        }
        return res;
    }
};