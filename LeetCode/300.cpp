class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vi;
        for(int i = 0; i < nums.size(); ++i) {
            int l = 0;
            int r = vi.size() - 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(vi[mid] < nums[i]) {
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
            if(l == vi.size()) {
                vi.push_back(nums[i]);
            }else {
                vi[l] = nums[i];
            }
        }
        return vi.size();
    }
};