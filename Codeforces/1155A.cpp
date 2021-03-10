#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num;
    string str;
    while(~scanf("%d", &num)) {
        cin >> str;
        if(num < 0) {
            printf("NO\n");
            return 0;
        }
        bool flag = false;
        int pos = -1;
        for(int i = 1; i < num; i++) {
            if(str[i] < str[i-1]) {
                flag = true;
                pos = i;
                break;
            }
        }
        if(flag) {
            printf("YES\n");
            printf("%d %d\n", pos, pos+1);
        }else {
            printf("NO\n");
        }
    }

    return 0;
}
