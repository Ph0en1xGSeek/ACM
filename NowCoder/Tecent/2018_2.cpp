#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> arr(num, 0);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long diff = 0;
    for(int i = 1; i <= num; ++i) {
        if((i & 1) == 1) {
            diff += arr[num - i];
        }else {
            diff -= arr[num - i];
        }
    }
    cout << diff << endl;
    return 0;
}