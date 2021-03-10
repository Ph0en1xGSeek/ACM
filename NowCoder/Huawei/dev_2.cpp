#include <iostream>
#include <set>

using namespace std;

int main() {
    int num, tmp;
    while(cin >> num) {
        set<int> st;
        for(int i = 0; i < num; ++i) {
            cin >> tmp;
            st.insert(tmp);
        }
        for(int item: st) {
            cout << item << endl;
        }
    }
    return 0;
}