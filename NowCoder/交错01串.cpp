#include <bits/stdc++.h>

using namespace std;


int main()
{
    string str;
    int cnt;
    int mx_cnt;
    while(cin >> str) {
        cnt = mx_cnt = 1;
        for(int i = 1; i < str.size(); ++i) {
            if(str[i] != str[i-1]) {
                ++cnt;
                if(cnt > mx_cnt) {
                    mx_cnt = cnt;
                }
            }else {
                cnt = 1;
            }
        }
        cout << mx_cnt << endl;
    }
    return 0;
}
