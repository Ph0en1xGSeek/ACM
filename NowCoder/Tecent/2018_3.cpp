#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        if(n > m) {
            cout << 0 << endl;
            continue;
        }else if(n == m) {
            cout << 1 << endl;
            continue;
        }else {
            int left = 1, right = m;
            while(left <= right) {
                int mid = left + ((right - left) >> 1);
                int tmp = mid;
                int sum = 0;
                for(int i = 0; i < n; ++i) {
                    sum += tmp;
                    tmp = ((tmp + 1) >> 1);
                }
                if(sum <= m) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
            cout << left - 1 << endl;
        }
    }
    return 0;
}