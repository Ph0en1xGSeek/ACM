#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{

    double a, b, c, d;
    int ans;
    double ans1, ans2;
    while(cin >> a >> b >> c >> d && a > 0)
    {
        if(a < b)
            swap(a, b);
        if(c < d)
            swap(c, d);

        ans1 = c/a;
        ans2 = d/b;
        ans1 = min(ans1, ans2) * 100;
        ans = (int)ans1;
       // ans = (int)(ans1 * 2);
       // ans++;
       // ans >>= 1;

        if(ans1 >= 1 && ans2 >= 1)
            printf("100%c\n", '%');
        else
            printf("%d%c\n", ans, '%');
    }
    return 0;
}
