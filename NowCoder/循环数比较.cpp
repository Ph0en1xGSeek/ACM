#include <bits/stdc++.h>

using namespace std;

int main() {
    string x1, x2;
    int k1, k2;
    while(cin >> x1 >> k1 >> x2 >> k2) {
        int len1 = x1.size();
        int len2 = x2.size();
        if(len1 * k1 < len2 * k2) {
            cout << "Less" << endl;
        }else if(len1 * k1 > len2 * k2) {
            cout << "Greater" << endl;
        }else {
            string str1 = "", str2 = "";
            for(int i = 0; i < k1; ++i) {
                str1 += x1;
            }
            for(int i = 0; i < k2; ++i) {
                str2 += x2;
            }
            if(str1 < str2) {
                cout << "Less" << endl;
            }else if(str1 > str2) {
                cout << "Greater" << endl;
            }else {
                cout << "Equal" << endl;
            }
        }
    }
    return 0;
}