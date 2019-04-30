#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    unordered_set<char> color_set;
    while(cin >> str) {
        color_set.clear();
        for(char c: str) {
            color_set.insert(c);
        }
        if(color_set.size() > 2) {
            cout << 0 << endl;
        }else {
            cout << color_set.size() << endl;
        }
    }
    return 0;
}
