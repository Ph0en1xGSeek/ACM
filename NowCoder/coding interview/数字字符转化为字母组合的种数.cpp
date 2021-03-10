#include <iostream>
#include <vector>

using namespace std;

int main() {
    const long long mod = 1e9 + 7;
    long long cur = 1, pre = 1, pre_pre = 0;
    string input;
    cin >> input;
    int size = input.size();
    if(size == 0) {
        cout << 0 << endl;
        return 0;
    }
    if(input[0] == '0') {
        cur = 0;
    }
    for(int i = 1; i < size; ++i) {
        pre_pre = pre;
        pre = cur;
        if(input[i] == '0') {
            cur = 0;
        }
        if(input[i-1] == '1') {
            cur = (cur + pre_pre) % mod;
        }else if(input[i-1] == '2' && input[i] >= '0' && input[i] <= '6') {
            cur = (cur + pre_pre) % mod;
        }
    }
    cout << cur << endl;
    return 0;
}