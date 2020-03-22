class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> ans(n);
		int tmp = n - k - 1;
		for(int i = 1; i <= tmp; ++i) {
			ans[i-1] = i;
		}
		int left = tmp + 1, right = n;
		while(left < right) {
			ans[tmp++] = left++;
			ans[tmp++] = right--;
		}
		if(tmp < n) {
			ans[tmp] = left;
		}
		return ans;
	}
};
