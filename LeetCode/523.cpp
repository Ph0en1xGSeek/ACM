class Solution {
public:
	bool checkSubarraySum(vector<int> &nums, int k) {
		int sz = nums.size();
		if(sz <= 1) {
			return false;
		}
		unordered_map<int, int> mp;
		mp[0] = -1;
		int sum = 0;
		for(int i = 0; i < sz; ++i) {
			sum += nums[i];
			if(k == 0) {
				if(mp.find(sum) != mp.end()){
                    if(i - mp[sum] > 1)
                        return true;
                }else {
                    mp[sum] = i;
                }
			}else if(k != 0) {
				if(mp.find(sum % k) != mp.end()) {
					if(i - mp[sum % k] > 1)
						return true;
				}else {
					mp[sum % k] = i;
				}
			}
		}
		return false;
	}
};