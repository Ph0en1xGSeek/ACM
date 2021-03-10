#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<bool> output(n+1, false);
    int expected = 1;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp == expected) {
            output[expected] = true;
            while(output[expected]) {
                cout << expected << " " << tmp << endl;
                ++expected;
            }
        }else {
            output[tmp] = true;
        }
    }
    return 0;
}