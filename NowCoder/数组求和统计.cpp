class Solution {
public:
	int countLR(vector<int> &a, vector<int> &b) {
		int size = a.size();
		if(size == 0) {
			return 0;
		}
		for(int i = 1; i < size; ++i) {
			a[i] += a[i-1];
		}
		int cnt = 0;
		for(int i = 0; i < size; ++i) {
			for(int j = i; j < size; ++j) {
				int accumulate;
				if(i == 0) {
					accumulate = a[j];
				}else {
					accumulate = a[j] - a[i-1];
				}
				if(b[j] + b[i] == accumulate) {
					++cnt;
				}
			}
		}
		return cnt;
	}
};