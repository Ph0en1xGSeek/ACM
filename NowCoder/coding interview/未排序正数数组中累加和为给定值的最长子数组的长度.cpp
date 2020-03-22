#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, k;
	while(cin >> n >> k) {
		vector<int> arr(n);
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int left = 0, right = 0;
		int sum = 0;
		int ans = -1;
		while(right < n) {
			sum += arr[right];
			++right;
			while(left < right && sum > k) {
				sum -= arr[left];
				++left;
			}
			if(sum == k) {
				sum == k;
				ans = max(ans, right - left);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
