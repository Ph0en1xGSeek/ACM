class Solution {
public:
	int sumSubarrayMins(vector<int> &A) {
		stack<pair<int, int> > st;
		int sz = A.size();
		if(sz == 0) {
			return 0;
		}
		int sum = 0;
		for(int i = 0; i < sz; ++i) {
			while(!st.empty() && A[st.top().first] > A[i]) {
				st.pop();
			}
			int cur_sum = 0;
			if(st.empty()) {
				cur_sum = ((long long)A[i] * (long long)(i+1)) % mod;
			}else {
				cur_sum = (((long long)A[i] * (long long)(i - st.top().first)) % mod + st.top().second) % mod;
			}
			st.push({i, cur_sum});
			sum = (sum + cur_sum) % mod;
		}
		return sum;
	}
private:
	const int mod = 1000000007;
};
