#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
 
string rev(string s) {
    bool flag = false;
    int size = s.size();
    string ret;
    for(int i = 0; i < size; ++i) {
        if(flag == false) {
            if(s[i] == '0') {
                flag = true;
            }else {
                continue;
            }
        }
        if(s[i] == '1') {
            ret += '0';
        }else {
            ret += '1';
        }
    }
    return ret;
}

int main() {
    int ca;
    string s, t;
    cin >> ca;
    while(ca--) {
        cin >> s >> t;
        int tsize = t.size();
        unordered_set<string> st;
        st.insert("0");
        while(s != "") {
            st.insert(s);
            s = rev(s);
        }
        vector<bool> dp(tsize+1, false);
        dp[0] = true;
        for(int i = 1; i <= tsize; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && st.find(t.substr(j, i-j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        if(dp[tsize]) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}