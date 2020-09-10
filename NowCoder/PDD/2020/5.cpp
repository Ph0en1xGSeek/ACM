#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    while(cin >> n >> m >> k) {
        k = n * m - k + 1;
        int l = 1, r = n * m;
        while(l < r) {
            int mid = l + ((r - l) >> 1);
            int row = mid / n;
            int cnt = row * n;
            // number of <= mid
            for(int i = row + 1; i <= m; ++i) {
                cnt += mid / i;
            }
            if(cnt < k) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        cout << l << endl;
    }
    return 0;
}