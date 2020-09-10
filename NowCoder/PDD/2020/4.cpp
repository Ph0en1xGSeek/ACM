#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mx = 0;
    vector<int> shai(n);
    for(int i = 0; i < n; ++i) {
        cin >> shai[i];
        mx = max(mx, shai[i]);
    }
    double pre = 0.0;
    double ans = 0.0;
    for(int i = 1; i <= mx; ++i) {
        double cur = 1.0;
        for(int j = 0; j < n; ++j) {
            cur *= min(i, shai[j]) * 1.0 / shai[j];
        }
        ans += i * (cur - pre);
        pre = cur;
    }
    cout << setprecision(2) << fixed <<ans << endl;
    return 0;
}