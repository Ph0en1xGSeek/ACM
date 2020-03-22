#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		vector<int> arr(n);
		int size = n / 2;
		for(int i = 1; i < n; i+=2) {
			cin >> arr[i];
		}
		for(int i = 0; i < n; i+=2) {
			cin >> arr[i];
		}
		for(int i = 0; i < n; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
