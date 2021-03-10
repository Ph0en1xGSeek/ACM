class Solution {
public:
	string getPermutation(int n, int k) {
		string num = "123456789";
		int A[10];
		A[0] = 1;
		for(int i = 1; i <= n; ++i) {
			A[i] = A[i-1] * i;
		}
        --k;
		string ret = "";
		for(int i = n; i > 0; --i) {
			int tmp = k / A[i-1];
			k %= A[i-1];
			ret.push_back(num[tmp]);
			num.erase(tmp, 1);
		}
		return ret;
	}
};