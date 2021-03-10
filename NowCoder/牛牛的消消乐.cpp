class Solution {
public:
	long long minimumValueAfterDispel(vector<int> &nums) {
		int size = nums.size();
		if(size == 0) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		long long sum = 0;
		for(auto num: nums) sum += num;
		long long dec = 0;
		for(int a = 0; a < size; ++a) {
			int ab = a;
			for(int b = 0; b <= a; ++b) {
				while(ab < size && nums[ab] < (long long)nums[a] + nums[b]) {
					++ab;
				}
				long long tmp = (long long)nums[b] * (a - b) + 
						(long long)nums[a] * (ab - a) + 
						((long long)nums[a] + nums[b]) * (size - ab);
				dec = max(dec, tmp);
			}
		}
		for(int a = 0; a < size; ++a) {
			int b = 0;
			for(int ab = a; ab < size; ++ab) {
				while(b < a && nums[ab] - nums[a] > nums[b]) {
					++b;
				}
				long long tmp = ((long long)nums[ab] - nums[a]) * (a - b) + 
						(long long)nums[a] * (ab - a) + 
						(long long)nums[ab] * (size - ab);
				dec = max(dec, tmp);
			}
		}
		for(int b = 0; b < size; ++b) {
			int a = b;
			for(int ab = b; ab < size; ++ab) {
				while(a < ab && nums[a] < nums[ab] - nums[b]) {
					++a;
				}
				long long tmp = (long long)nums[b] * (a - b) + 
						((long long)nums[ab] - nums[b]) * (ab - a) + 
						(long long)nums[ab] * (size - ab);
				dec = max(dec, tmp);
			}
		}
		return sum - dec;
	}
};
