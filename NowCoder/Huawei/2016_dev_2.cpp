#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string str;
    bool vis[128] = {false};
    while(cin >> str) {
        int size = str.size();
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < size; ++i) {
            if(vis[str[i]] == false) {
                cout << str[i];
                vis[str[i]] = true;
            }
        }
        cout << endl;
    }
    return 0;
}