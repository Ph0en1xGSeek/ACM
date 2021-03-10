#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	string str1, str2;
	int cnt1, cnt2;
	while(cin >> str1 >> str2) {
		int size = str1.size();
		if(size == 0) {
			cout << 0 << endl;
			continue;
		}
		cnt1 = cnt2 = 0;
		for(int i = 0; i < size; ++i) {
			if(str1[i] == 'A' && str2[i] == 'T') {
				++cnt1;
			}else if(str1[i] == 'T' && str2[i] == 'A') {
				++cnt2;
			}
		}
		if(cnt1 < cnt2) {
			cout << cnt2 << endl;
		}else {
			cout << cnt1 << endl;
		}
	}
	return 0;
}