#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
 
int main() {
    int ca;
    long long a, b, c;
    long long sum, mx;
    cin >> ca;
    while(ca--) {
        sum = 0;
        mx = -1;
        cin >> a >> b >> c;
        mx = max(a, b);
        mx = max(mx, c);
        sum = a + b + c;
        if((sum - mx) * 2 >= mx) {
            cout << sum / 3 << endl;
        }else {
            cout << sum - mx << endl;
        }
    }
    return 0;
}