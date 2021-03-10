#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int T, num;
    scanf("%d", &T);
    string str;
    while(T--) {
        scanf("%d", &num);
        cin >> str;
        int cnt = 0;
        int pos = 0;
        while(pos < num) {
            while(pos < num && str[pos] == 'X') ++pos;
            if(pos < num) {
                ++cnt;
                pos += 3;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}