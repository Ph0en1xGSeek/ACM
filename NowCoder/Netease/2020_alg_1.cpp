#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int ca;
    cin >> ca;
    long long a, b, c;
    while(ca--) {
        cin >> a >> b >> c;
        if(a < b) {
            swap(a, b);
        }
        if(b < c) {
            swap(b, c);
        }
        if(a < b) {
            swap(a, b);
        }
        cout << max((a + b + c + 2) / 3, (a + 1) / 2) << endl;
    }
    return 0;
}