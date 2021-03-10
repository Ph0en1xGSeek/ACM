#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    if(arr[0] < arr[num-1]) {
        cout << arr[0];
        return 0;
    }
    int left = 0, right = num - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(arr[mid] > arr[right]) {
            left = mid + 1;
        }else if(arr[mid] < arr[left]) {
            right = mid - 1;
        }else {
            --right;
        }
    }
    cout << arr[left] << endl;
}