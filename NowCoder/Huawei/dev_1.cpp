#include <iostream>
 using namespace std;

int main() {
    int num;
    int ans = 0;
    while(cin >> num && num != 0) {
        ans = 0;
        while(num != 0) {
            ans += num / 3;
            if(num / 3 >= 1) {
                num = num % 3 + num / 3;
            }else {
                if(num % 3 == 2) {
                    ++ans;
                }
                num = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}