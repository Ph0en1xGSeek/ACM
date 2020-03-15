#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    long long num;
    int k;
    string output;
    while(cin >> num >> k) {
        output = "";
        if(num == 0) {
            cout << "0" << endl;
            continue;
        }
        while(num > 0) {
            int remain = num % k;
            output += '0' + remain;
            num /= k;
        }
        reverse(output.begin(), output.end());
        cout << output << endl;
    }
    return 0;
}