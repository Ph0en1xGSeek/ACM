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
    int cnt = 0;
    int pos = 0;
    int right = 0;
    int tmp_right;
    while(pos < num && right < num-1) {
        ++cnt;
        tmp_right = right;
        while(pos <= tmp_right) {
            right = max(right, pos + arr[pos]);
            ++pos;
        }
    }
    cout << cnt << endl;
    return 0;
}