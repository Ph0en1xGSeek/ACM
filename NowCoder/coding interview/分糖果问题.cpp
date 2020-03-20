#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		int ans = 0;
		if(n == 0) {
			cout << 0 << endl;
		}
		vector<int> num(n), cnt(n, 1);
		for(int i = 0; i < n; ++i) {
			cin >> num[i];
		}
		for(int i = 1; i < n; ++i) {
			if(num[i] > num[i-1]) {
				cnt[i] = cnt[i-1] + 1;
			}
		}
		int tmp = 1;
		for(int i = n-2; i >= 0; --i) {
			if(num[i] > num[i+1]) {
                ++tmp;
				cnt[i] = max(cnt[i], tmp); 
			}else {
				tmp = 1;
			}
		}
		for(int i = 0; i < n; ++i) {
			ans += cnt[i];
		}
		cout << ans << endl;
	}
	return 0;
}