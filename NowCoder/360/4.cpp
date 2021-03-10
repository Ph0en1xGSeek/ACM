#include <iostream>
#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int main() {
    int ca;
    cin >> ca;
    int num;
    while(ca--) {
        cin >> num;
        vector<int> arr(num * 2);
        for(int i = 0; i < 2 * num; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if(arr[num] > arr[num - 1]) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}