#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int ca, num, tmp;
    int cnt = 0;
    cin >> ca;
    while(ca--) {
        unordered_set<int> st;
        cin >> num;
        for(int i = 0; i < num; ++i) {
            cin >> tmp;
            cnt = 0;
            while(tmp > 0) {
                ++cnt;
                tmp = (tmp - 1) & tmp;
            }
            st.insert(cnt);
        }
        cout << st.size() << endl;
    }
    return 0;
}