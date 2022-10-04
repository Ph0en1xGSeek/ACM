class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if (size < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < size - 2) {
            j = i + 1;
            k = size - 1;
            while(j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> cur_res(3);
                    cur_res[0] = nums[i];
                    cur_res[1] = nums[j];
                    cur_res[2] = nums[k];
                    res.push_back(cur_res);
                    do {
                        ++j;
                    } while (j < k && nums[j] == nums[j-1]);
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    do {
                        ++j;
                    } while (j < k && nums[j] == nums[j-1]);
                } else {
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
            }
            do {
                ++i;
            } while(i < size - 2 && nums[i] == nums[i-1]); 
        }
        return res;
    }
};