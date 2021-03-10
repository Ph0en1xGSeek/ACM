class Solution {
public:
	int findMinMoves(vector<int> &machines) {
		int sz = machines.size();
		if(sz == 0) {
			return 0;
		}
		int sum = accumulate(machines.begin(), machines.end(), 0);
		if(sum % sz != 0) {
			return -1;
		}
		int res = 0, cnt = 0, avg = sum / sz;
		for(int machine : machines) {
			cnt += machine - avg;
			res = max(res, max(abs(cnt), machine - avg));
			// cnt: +/- accumulate from 0 to i
			// abs(cnt): I have to output to or receive from right neighbor
			// machine - sz: I have to output to other
		}
		return res;
	}
};