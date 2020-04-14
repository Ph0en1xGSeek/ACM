#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    long long output;
    while(cin >> str) {
        output = 0;
        long long base = 1;
        long long num;
        int size = str.size();
        for(int i = size-1; i >= 2; --i) {
            if(str[i] >= '0' && str[i] <= '9') {
                num = str[i] - '0';
            }else {
                num = str[i] - 'A' + 10;
            }
            output += num * base;
            base *= 16;
        }
        cout << output << endl;
    }
    return 0;
}