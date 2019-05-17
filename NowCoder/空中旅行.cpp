#include <iostream>

using namespace std;

int main() {
    int n, s;
    int tmp;
    int tot;
    int ans = -1;
    while(cin >> n >> s) {
        tot = 0;
        for(int i = 0; i < n; ++i) {
            cin >> tmp;
            tot += tmp;
            if(ans < 0 && tot > s) {
                ans = i;
            }
        }
        if(ans == -1) {
            ans = n;
        }
        cout << ans << endl;
    }
    return 0;
}