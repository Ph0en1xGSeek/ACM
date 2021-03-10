class Solution {
public:
	pair<int, int> readNumber(string &str) {
		int num = 0;
		int sign = 1;
		int pos = 0;
		pair<int, int> ans;
		if(str[pos] == '-') {
			sign = -1;
			++pos;
		}
		while(str[pos] != '+') {
			num *= 10;
			num += str[pos] - '0';
			++pos;
		}
		ans.first = sign * num;
		++pos;
		num = 0;
		sign = 1;
		if(str[pos] == '-') {
			sign = -1;
			++pos;
		}
		while(str[pos] != 'i') {
			num *= 10;
			num += str[pos] - '0';
			++pos;
		}
		ans.second = sign * num;
		return ans;
	}
	
	string complexNumberMultiply(string a, string b) {
		pair<int, int> num1 = readNumber(a);
		pair<int, int> num2 = readNumber(b);
		int real = num1.first * num2.first - num1.second * num2.second;
		int complex = num1.first * num2.second + num1.second * num2.first;
		stringstream os;
		os << real << '+' << complex << 'i';
		string ans = os.str();
		return ans;
	}
};
