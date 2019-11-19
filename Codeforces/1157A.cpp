#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
    int num;
    while(~scanf("%d", &num)) {
        int cnt = 0;
        int jin = 0;
        while(num > 0) {
            int tmp = num % 10 + jin;
            if(num / 10 > 0) {
                cnt += (9 - tmp + 1);
            }else {
                cnt += 9;
            }
            num /= 10;
            jin = 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}