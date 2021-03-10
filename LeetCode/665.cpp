class Solution {
public:
	bool checkPossibility(vector<int> &nums) {
		int size = nums.size();
		if(size <= 1) {
			return true;
		}
		bool changed = false;
		for(int i = 1; i < size; ++i) {
			if(nums[i-1] > nums[i]) {
				if(changed == true) {
                    return false;
                }
                changed = true;
                if(i == 1 || nums[i] > nums[i-2]) {
                    nums[i-1] = nums[i];
                }else {
                    nums[i] = nums[i-1];
                }
			}
		}
		return true;
	}
};
