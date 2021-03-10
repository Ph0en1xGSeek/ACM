#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    int num;
    string str;
    while(~scanf("%d", &num))
    {
        getchar();
        getline(cin, str);
        int ans = 0;
        int tmp = 0;
        for(int i = 0; i < num; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                tmp++;
            else if(str[i] == ' ')
            {
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
        ans = max(ans, tmp);

        printf("%d\n", ans);
    }
    return 0;
}
