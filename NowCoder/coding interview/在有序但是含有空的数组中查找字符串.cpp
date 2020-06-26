#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	cin >> str;
	vector<string> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int left = 0;
	int right = n - 1;
	while(left <= right) {
		int mid = ((right - left) >> 1) + left;
        int tmp = mid;
		while(tmp > left && arr[tmp] == "0") {
			--tmp;
		}
        if(tmp < left || arr[tmp] < str) {
            left = mid + 1;
        }else {
            right = tmp - 1;
        }
	}
    if(left < n && arr[left] == str)
	    cout << left << endl;
    else 
        cout << -1 << endl;
	return 0;
}
