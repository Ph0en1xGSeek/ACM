#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    while(cin >> n) {
        n = 1024 - n;
        cnt += n / 64;
        n %= 64;
        cnt += n / 16;
        n %= 16;
        cnt += n / 4;
        n %= 4;
        cnt += n;
        cout << cnt << endl;
    }
    return 0;
}