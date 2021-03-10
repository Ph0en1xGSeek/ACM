#include <stdio.h>
#include <iostream>
#include <vector>
 
using namespace std;
 
char mp[55][55];
 
 
int main() {
    int n;
    for(int i = 0; i < 55; ++i) {
        for(int j = 0; j < 55; ++j) {
            mp[i][j] = '#';
        }
    }
    while(~scanf("%d", &n)) {
        bool ret = false;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", &mp[i][1]);
            mp[i][n+1] = '#';
        }
        for(int i = 1; i <= n && !ret; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(mp[i][j] == '.') {
                    if(mp[i+1][j] == '#' || mp[i+1][j+1] == '#' || mp[i+1][j-1] == '#' || mp[i+2][j] == '#') {
                        printf("NO\n");
                        ret = true;
                        break;
                    }else {
                        mp[i][j] = mp[i+1][j-1] = mp[i+1][j] = mp[i+1][j+1] = mp[i+2][j] = '#';
                    }
                }
 
            }
        }
        if(!ret)
            printf("YES\n");
    }
    return 0;
}