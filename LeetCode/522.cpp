class Solution {
public:
	bool isSubsequence(string &a, string &b) {
		int size_a = a.size();
		int size_b = b.size();
		if(size_b > size_a) {
			return false;
		}
		int i = 0, j = 0;
		for(i = 0; i < size_b; ++i) {
			while(j < size_a && b[i] != a[j]) {
				++j;
			}
			if(j == size_a) {
				break;
			}
            ++j;
		}
		if(i == size_b) {
			return true;
		}else {
			return false;
		}
		
	}

	int findLUSlength(vector<string> &strs) {
		int strs_size = strs.size();
		if(strs_size == 0) {
			return -1;
		}
		int ans = -1;
		bool flag = true;
		for(int i = 0; i < strs_size; ++i) {
			flag = true;
            if((int)strs[i].size() <= ans) {
                continue;
            }
			for(int j = 0; j < strs_size; ++j) {
				if(i == j) {
					continue;
				}
				if(isSubsequence(strs[j], strs[i])) {
					flag = false;
					break;
				}
			}
			if(flag == true) {
				ans = (int)strs[i].size();
			}
		}
		return ans;
	}
};