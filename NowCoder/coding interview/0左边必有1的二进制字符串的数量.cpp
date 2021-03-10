#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	const int Mod = (1 << 29);
	while(cin >> n) {
		int one = 1;
		int zero = 0;
		for(int i = 2; i <= n; ++i) {
			int tmp = one;
			one = (zero + one) % Mod;
			zero = tmp;
		}
		cout << (one + zero) % Mod << endl;
	}
	return 0;
}
