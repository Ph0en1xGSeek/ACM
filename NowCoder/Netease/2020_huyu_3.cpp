#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ca;
    int m, t, m1, t1, m2, t2;
    cin >> ca;
    while(ca--) {
        cin >> m >> t >> m1 >> t1 >> m2 >> t2;
        int size = t;
        vector<int> arr(size + 1, 0);
        for(int i = 1; i <= size; ++i) {
            if(((i - 1) / t1) % 2 == 0) {
                arr[i] += m1;
            }
            if(((i - 1) / t2) % 2 == 0) {
                arr[i] -= m2;
            }
            arr[i] += arr[i-1];
            if(arr[i] > m) {
                arr[i] = m;
            }else if(arr[i] < 0) {
                arr[i] = 0;
            }
        }
        cout << arr[t] << endl;
    }
    return 0;
}