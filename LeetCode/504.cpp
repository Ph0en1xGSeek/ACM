class Solution {
public:
	string convertToBase7(int num) {
        if(num == 0) {
            return "0";
        }
		bool sign = true;
		if(num < 0) {
			sign = false;
			num = -num;
		}
		string ans;
		int tmp;
		while(num > 0) {
			tmp = num % 7;
			ans += char(tmp + '0');
			num /= 7;
		}
		if(!sign) {
			ans.push_back('-');
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};