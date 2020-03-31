#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isHu(vector<int> &arr, int from) {
	bool flag = false;
    for(int i = from; i < 9; ++i) {
        if(arr[i] > 0) {
            if(arr[i] >= 3) {
                arr[i] -= 3;
                if(isHu(arr, i)) {
					arr[i] += 3;
                    return true;
                }
                arr[i] += 3;
            }
            if(i + 2 >= 9) {
                return false;
            }
            if(arr[i] && arr[i+1] && arr[i+2]) {
                --arr[i];
                --arr[i+1];
                --arr[i+2];
                flag = isHu(arr, i);
				++arr[i];
				++arr[i+1];
				++arr[i+2];
            }
			return flag;
        }
    }
    return true;
}

int main() {
    int tmp;
    bool flag = false;
    while(cin >> tmp) {
        vector<int> arr(9, 0);
        ++arr[tmp-1];
        for(int i = 0; i < 12; ++i) {
            cin >> tmp;
            ++arr[tmp-1];
        }
        for(int i = 0; i < 9; ++i) {
            if(arr[i] < 4) {
                ++arr[i];
                for(int j = 0; j < 9; ++j) {
                    if(arr[j] >= 2) {
                        arr[j] -= 2;
                        if(isHu(arr, 0)) {
                            flag = true;
                            cout << i+1 << " ";
                            arr[j] += 2;
                            break;
                        }
                        arr[j] += 2;
                    }
                }
                --arr[i];
            }
        }
        if(flag == false) {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}