#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    string str;
    for(int i = 0; i < num; ++i) {
        cin >> str;
        int h = (str[0] - '0') * 10 + str[1] - '0';
        if(h > 23) {
            str[0] = '0';
        }
        int m = (str[3] - '0') * 10 + str[4] - '0';
        if(m > 59) {
            str[3] = '0';
        }
        int s = (str[6] - '0') * 10 + str[7] - '0';
        if(s > 59) {
            str[6] = '0';
        }
        cout << str << endl;
    }
    return 0;
}