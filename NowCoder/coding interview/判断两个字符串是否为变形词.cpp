#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string str1, str2;
    cin >> str1 >> str2;
    bool flag = true;
    if(n != m) {
        cout << "false" << endl;
        return 0;
    }
    vector<int> cnt1(128), cnt2(128);
    for(int i = 0; i < n; ++i) {
        ++cnt1[str1[i]];
        ++cnt2[str2[i]];
    }
    for(int i = 0; i < 128; ++i) {
        if(cnt1[i] != cnt2[i]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "true" << endl;
    }else {
        cout << "false" << endl;
    }
    return 0;
}