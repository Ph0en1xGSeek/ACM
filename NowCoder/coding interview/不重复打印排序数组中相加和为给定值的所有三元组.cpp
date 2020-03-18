#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
	long long n, k;
	while(cin >> n >> k) {
		if(n == 0) {
			continue;
		}
		vector<long long> arr(n);
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		for(int i = 0; i < n; ++i) {
			if(arr[i] * 3 > k) {
				break;
			}
			int left = i + 1, right = n - 1;
            while(arr[left] == arr[left-1]) {
                ++left; //???????
            }
            bool flag_left = false;
            bool flag_right = false;
			while(left < right) {
                flag_left = flag_right = false;
				if(arr[i] + arr[left] + arr[right] == k) {
					cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
					++left;
					--right;
                    flag_left = flag_right = true;
				}else if(arr[i] + arr[left] + arr[right] < k) {
					++left;
                    flag_left = true;
				}else {
					--right;
                    flag_right = true;
				}
                if(flag_left) {
                    while(left < right && arr[left] == arr[left - 1]) {
                        ++left;
                    }
                }
				if(flag_right) {
                    while(left < right && arr[right] == arr[right + 1]) {
                        --right;
                    }
                }
			}
			while(i + 1 < n && arr[i] == arr[i+1]) {
				++i;
			}
		}
	}
	return 0;
}
