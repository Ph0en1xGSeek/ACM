#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool isScramble(string &s1, int from1, int to1, string &s2, int from2, int to2) {
	vector<int> cnt(128, 0);
	bool equal = true;
	for(int i = from1, j = from2; i <= to1; ++i, ++j) {
		if(equal && s1[i] != s2[j]) {
			equal = false;
		}
		++cnt[s1[i]];
		--cnt[s2[j]];
	}
	if(equal) {
		return true;
	}
	for(int i = 0; i < 128; ++i) {
		if(cnt[i] != 0) {
			return false;
		}
	}
	for(int i = 0; i < to1 - from1; ++i) {
		if((isScramble(s1, from1, from1 + i, s2, from2, from2 + i) && 
            isScramble(s1, from1 + i + 1, to1, s2, from2 + i + 1, to2)) || 
            isScramble(s1, from1, from1 + i, s2, to2 - i, to2) && 
            isScramble(s1, from1 + i + 1, to1, s2, from2, to2 - i - 1)) {
			return true;
		}
	}
	return false;
}

int main() {
	string s1, s2;
	while(cin >> s1 >> s2) {
		int size1 = s1.size();
		int size2 = s2.size();
		if(size1 != size2) {
			cout << "NO" << endl;
			continue;
		}
		if(isScramble(s1, 0, size1-1, s2, 0, size2-1)) {
			cout << "YES" << endl;
		}else {
			cout << "NO" << endl;
		}
	}
}
