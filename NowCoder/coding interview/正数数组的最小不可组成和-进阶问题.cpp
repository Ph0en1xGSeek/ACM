#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long max_sum = 0;
    for(int i = 0; i < num; ++i) {
        if(arr[i] > max_sum + 1) {
            break;
        }else {
            max_sum += arr[i];
        }
    }
    cout << max_sum + 1 << endl;
    return 0;
}