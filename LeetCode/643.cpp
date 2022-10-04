class Solution {
public:
	double findMaxAverage(vector<int> &nums, int k) {
		int sz = nums.size();
		if(sz < k) {
			return 0.0;
		}
		double sum = 0.0;
		double mx= 0.0;
		for(int i = 0; i < k; ++i) {
			sum += nums[i];
		}
		mx = sum;
		for(int i = k; i < sz; ++i) {
			sum -= nums[i - k];
			sum += nums[i];
			mx = max(mx, sum);
		}
		return mx / k;
	}
};