#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main() {
    string str;
    string res;
    bool flag[26];
    while(cin >> str) {
        res = "";
        memset(flag, false, sizeof(flag));
        for(int i = 0; i < str.size(); ++i) {
            if(flag[str[i] - 'a']) {
                continue;
            }else {
                flag[str[i] - 'a'] = true;
                res += str[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}