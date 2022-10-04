class Solution {
public:
	bool isMonotonic(vector<int> &A) {
		int size = A.size();
		if(size <= 2) {
			return true;
		}
		int state = 0;
		for(int i = 1; i < size; ++i) {
			if(A[i] - A[i-1] > 0) {
				if(state == -1) {
					return false;
				}else if(state == 0) {
					state = 1;
				}
			}else if(A[i] - A[i-1] < 0) {
				if(state == 1) {
					return false;
				}else if(state == 0) {
					state = -1;
				}
			}
		}
		return true;
	}
};
