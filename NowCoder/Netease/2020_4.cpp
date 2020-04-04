#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int mx = (1 << 17)-1;

int main() {
    int q, x, op, pos;
    cin >> q;
    unordered_map<int, int> mp;
    mp[0] = 0;
    while(q--) {
        cin >> op >> x;
        if(op == 1) {
            if(mp[x] == x) {
                continue;
            }
            pos = (mx ^ x);
            for(int i = pos; i != 0; i = (i-1) & pos) {
                if(mp.find(i^x) == mp.end()) {
                    mp[i^x] = 0;
                }
                mp[i^x] |= x;
            }
            mp[x] = x;
        }else {
            if(mp[x] != x) {
                cout << "NO" << endl;
            }else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}