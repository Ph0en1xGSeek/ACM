#include <iostream>
#include <stdio.h>
#include <vector>
 
using namespace std;
 
int main() {
    int ca, num;
    cin >> ca;
    int x1, y1, x2, y2;
    int ans = 0;
    while(ca--) {
        cin >> num;
        ans = 0;
        for(int i = 0; i < num; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            ans += (x2 - x1 + 1) * (y2 - y1 + 1);
        }
        cout << ans << endl;
    }
    return 0;
}