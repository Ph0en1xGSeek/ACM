#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
    const int INT_MAX = 0x7fffffff;
    const int INT_MIN = 0xffffffff;
	int n;
	int ans;
	while(cin >> n) {
        if(n <= 0) {
            cout << 0 << endl;
            continue;
        }
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        ans = 0;
        for(int i = 0; i < n; ++i) {
            int mi = INT_MAX;
            int mx = INT_MIN;
            for(int j = i; j < n; ++j) {
                mi = min(mi, arr[j]);
                mx = max(mx, arr[j]);
                if(j - i == mx - mi) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        cout << ans << endl;
	}
	return 0;
}