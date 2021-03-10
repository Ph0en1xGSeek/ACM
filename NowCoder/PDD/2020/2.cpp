#include <iostream>

using namespace std;

int getMin(int num) {
    if(num % 4 == 1 || num % 4 == 2) {
        return 1;
    }
    return 0;
}

int main() {
    int T;
    int num;
    cin >> T;
    while(T--) {
        cin >> num;
        cout << getMin(num) << " " << num - getMin(num - 1) << endl;
    }
    return 0;
}