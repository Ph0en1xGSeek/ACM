#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, target;
    cin >> num >> target;
    vector<int> arr(num);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    int left = 0, right = num - 1;
    bool flag = false;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(arr[mid] == target) {
            flag = true;
            break;
        }else if(arr[mid] > arr[left]) {
            if(arr[left] <= target && arr[mid] > target) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }else if(arr[mid] < arr[left]) {
            if(arr[mid] < target && arr[right] >= target) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }else {
            --right;
        }
    }
    if(flag) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}