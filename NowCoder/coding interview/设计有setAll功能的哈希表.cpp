#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    unordered_map<int, int> mp;
    unordered_set<int> st;
    int all_value = -1;
    int op, x, y;
    for(int i = 0; i < num; ++i) {
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            mp[x] = y;
            st.insert(x);
        }else if(op == 2) {
            cin >> x;
            if(st.find(x) == st.end()) {
                cout << -1 << endl;
            }else if(mp.find(x) == mp.end()) {
                cout << all_value << endl;
            }else {
                cout << mp[x] << endl;
            }
        }else {
            cin >> x;
            mp.clear();
            all_value = x;
        }
    }
    return 0;
}