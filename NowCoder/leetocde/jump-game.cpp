class Solution {
public:
	bool canJump(int A[], int n) {
		if(n <= 1) {
			return true;
		}
		int right = 0;
		for(int i = 0; i < n; ++i) {
			if(i > right) {
				return false;
			}
			right = max(A[i] + i, right);
			if(right >= n-1) {
				return true;
			}
		}
		return false;
	}
};