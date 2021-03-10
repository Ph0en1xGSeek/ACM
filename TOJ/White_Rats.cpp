#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int num;
    while(t--)
    {
        scanf("%d", &num);
        int ans = 0;
        while(num != 1)
        {
            int tmp = num / 2;
            num = max(tmp, num - tmp);
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
