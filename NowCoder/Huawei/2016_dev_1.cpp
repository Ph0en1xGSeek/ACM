#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int ans, n;
    while(cin >> n) {
        ans = 0;
        for(int i = 2; i <= n; ++i) {
            ans = (ans + 3) % i;
        }
        cout << ans << endl;
    }
    return 0;
}