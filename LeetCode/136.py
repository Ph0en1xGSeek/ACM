class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tot = 0
        for i in range(len(nums)):
            tot ^= nums[i]
        return tot


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = 0;
        for(int item: nums) {
            tmp ^= item;
        }
        return tmp;
    }
};