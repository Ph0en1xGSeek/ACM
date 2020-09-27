class Solution(object):  
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        if len(nums) < 3:
            return []
        nums.sort()
        for i in range(len(nums) - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i+1
            r = len(nums)-1
            while l < r:
                if nums[i] + nums[l] + nums[r] > 0:
                    r -= 1
                elif nums[i] + nums[l] + nums[r] < 0:
                    l += 1
                else:
                    ans.append([nums[i], nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                    r -= 1
                    while l < r and nums[r] == nums[r+1]:
                        r -= 1
                    
        return ans


class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		int size = nums.size();
		vector<vector<int>> ans;
		if(size < 3) {
			return ans;
		}
		sort(nums.begin(), nums.end());
		for(int i = 0; i < size - 2; ++i) {
            if(i != 0 && nums[i-1] == nums[i]) {
                continue;
            }
			int l = i + 1;
			int r = size - 1;
			while(l < r) {
				if(nums[l] + nums[r] < -nums[i]) {
					++l;
					while(l < r && nums[l] == nums[l - 1]) {
						++l;
					}
				}else if(nums[l] + nums[r] > -nums[i]) {
					--r;
					while(l < r && nums[r] == nums[r + 1]) {
						--r;
					}
				}else {
					ans.push_back({nums[i], nums[l], nums[r]});
					++l;
					--r;
					while(l < r && nums[l] == nums[l-1]) {
						++l;
					}
					while(l < r && nums[r] == nums[r + 1]) {
						--r;
					}
				}
			}
		}
		return ans;
	}
};
