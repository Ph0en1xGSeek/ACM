#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n, k;
	while(cin >> n >> k) {
		if(n == 0) {
			continue;
		}
		int sum = 0;
		int cur;
		int ans = -1;
		unordered_map<int, int> pos;
		pos[0] = -1;
		for(int i = 0; i < n; ++i) {
			cin >> cur;
			sum += cur;
			if(pos.find(sum - k) != pos.end()) {
				ans = max(ans, i - pos[sum - k]);
			}
			if(pos.find(sum) == pos.end()) {
				pos[sum] = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
