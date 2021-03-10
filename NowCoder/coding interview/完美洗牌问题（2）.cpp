#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		vector<int> arr(n);
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int left = 0, right = n-1;
		while(left < right) {
			cout << arr[left] << " " << arr[right] << " ";
			++left;
			--right;
		}
		if(left == right) {
			cout << arr[left];
		}
		cout << endl;
	}
	return 0;
}
