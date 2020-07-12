#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;


int main() {
	string tmp;
	cin >> tmp;
	int size = tmp.size();
	if(size == 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<char> str(size * 2 + 3);
	str[0] = '$';
	str[size * 2 + 2] = '@';
	str[size * 2 + 1] = '#';
	for(int i = 0; i < size; ++i) {
		str[i * 2 + 1] = '#';
		str[i * 2 + 2] = tmp[i];
	}
	int id = 0;
	int bound = 0;
	int ans = 0;
	size = size * 2 + 1;
	vector<int> p(size, 1);
	for(int i = 2; i < size; ++i) {
		if(i < bound) {
			p[i] = min(p[2 * id - i], bound - i);
		}
		while(str[i + p[i]] == str[i - p[i]]) {
			++p[i];
		}
		if(i + p[i] > bound) {
			bound = i + p[i];
			id = i;
		}
		ans += p[i] / 2;
	}
	cout << ans << endl;
	return 0;
}