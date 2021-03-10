#include <iostream>
using namespace std;

int main() {
    int T;
    int num;
    cin >> T;
    while(T--) {
        cin >> num;
        int i;
        for(i = 0; i < 32; ++i) {
            if((1 << i) > num) {
                break;
            }
        }
        cout << i << endl;
    }
    return 0;
}