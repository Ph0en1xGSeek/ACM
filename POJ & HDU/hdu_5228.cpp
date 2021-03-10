#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool flag[4][18];

char str;
int num;

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(flag, false, sizeof(flag));
        for(int i = 0; i < 5; i++)
        {
            cin >> str;
            cin >> num;
//            cout << str << "   " << num << endl;
            flag[str-'A'][num] = true;
        }
        int ans = 5;
        for(int i = 1; i <= 10; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                int tmp = 0;
                for(int k = 0; k < 5; k++)
                {
                    if(!flag[j][(i+k - 1)%13 + 1])
                        tmp++;
                }
                ans = min(ans, tmp);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
