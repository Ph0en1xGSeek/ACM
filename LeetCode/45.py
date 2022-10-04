class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = 0
        l = 0
        r = 0
        next_r = 0
        while r < len(nums) - 1:
            for i in range(l, r+1):
                next_r = max(next_r, i+nums[i])
            l = r + 1
            r = next_r
            k += 1
        return k


class Solution {
public:
	int jump(vector<int> &nums) {
        int n = nums.size();
		if(n == 1) {
			return 0;
        } 
        int l = 0, r = 0;
        int k = 0;
        int max_r = 0;
        while(r < n-1) {
            ++k;
            for(int i = l; i <= r; ++i) {
                max_r = max(max_r, i + nums[i]);
            }
            l = r + 1;
            r = max_r;
        }
        return k;
	}
};