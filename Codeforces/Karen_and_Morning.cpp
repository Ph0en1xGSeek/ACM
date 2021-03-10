#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {
    int hh, mm;
    int cnt;
    while (scanf("%d:%d", &hh, &mm) != EOF)
    {
        cnt = 0;
        while ((hh/10)%10 != mm%10 || (mm/10)%10 != hh%10)
        {
            cnt++;
            mm++;
            if(mm == 60)
            {
                hh++;
                mm = 0;
            }
            if(hh == 24)
                hh = 0;
        }
        printf("%d\n", cnt);
    }
    return 0;
}