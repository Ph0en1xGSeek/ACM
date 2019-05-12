#include <iostream>

using namespace std;

int main() {
    int n, t, a;
    while(cin >> n >> t >> a) {
        if(t < a) {
            cout << t + (n - a) << endl;
        }else {
            cout << a + (n - t) << endl;
        }
    }
    return 0;
}