class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        for(int i = 1; i < size; ++i) {
            if((i & 1) == 0) {
                if(nums[i] < nums[i-1]) {
                    swap(nums[i], nums[i-1]);
                }
            }else {
                if(nums[i] > nums[i-1]) {
                    swap(nums[i], nums[i-1]);
                }
            }
        }
    }
};