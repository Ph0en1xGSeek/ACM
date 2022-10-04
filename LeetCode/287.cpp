class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) {
            return -1;
        }
        int fast = nums[nums[0]];
        int slow = nums[0];
        while(fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        
        fast = 0;
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return fast;
    }
};