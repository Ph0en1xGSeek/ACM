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
    int cur = 0;
    for(int i = num-1; i >= 0; --i) {
        cur = (cur + arr[i] + 1) / 2;
    }
    cout << cur << endl;
    return 0;
}