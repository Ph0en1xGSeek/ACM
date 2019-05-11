#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    string str;
    while(cin >> str) {
        int cnt = 0;
        while(1) {
            unordered_set<string> st;
            for(int i = 0; i < str.size() - cnt; ++i) {
                st.insert(str.substr(i, cnt+1));
            }
            if(st.size() < pow(4, cnt+1))
                break;
            ++cnt;
        }
        cout << cnt+1 << endl;
    }
    return 0;
}