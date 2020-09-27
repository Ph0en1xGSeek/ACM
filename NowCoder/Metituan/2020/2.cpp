#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    while(cin >> str) {
        int size = str.size();
        vector<char> ex_str(size * 2 + 3);
        vector<int> p(size * 2 + 3);
        ex_str[0] = '&';
        ex_str[1] = '#';
        ex_str[size * 2 + 2] = '@';
        for(int i = 0; i < size; ++i) {
            ex_str[(i << 1) + 2] = str[i];
            ex_str[(i << 1) + 3] = '#';
        }
        int id = 0;
        int bound = 0;
        int pos = 0;
        int ans = 0;
        while(pos < size * 2 + 3) {
            if(pos < bound) {
                p[pos] = min(p[2 * id - pos], bound - pos);
            }else {
                p[pos] = 1;
            }
            while(ex_str[pos + p[pos]] == ex_str[pos - p[pos]]) {
                ++p[pos];
            }
            if(pos + p[pos] > bound) {
                bound = pos + p[pos];
                id = pos;
            }
            ans += p[pos] / 2;
            ++pos;
        }
        cout << ans << endl;
    }
    return 0;
}