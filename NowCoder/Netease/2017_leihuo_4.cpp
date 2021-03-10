#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double ans;
    while(cin >> n) {
        ans = 1.0;
        for(int i = 1; i < n; ++i) {
            ans += 1.0 / (i+1);
        }
        cout << fixed << setprecision(4) << ans << endl;
    }
    return 0;
}