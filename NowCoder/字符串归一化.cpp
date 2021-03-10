#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main() {
    string str;
    int cnt[26];
    while(cin >> str) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < str.size(); ++i) {
            ++cnt[str[i] - 'a'];
        }
        for(int i = 0 ; i < 26; ++i) {
            if(cnt[i] > 0) {
                printf("%c%d", i + 'a', cnt[i]);
            }
        }
        printf("\n");
    }
    return 0;
}