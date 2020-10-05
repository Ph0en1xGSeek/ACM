#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str[100005];
int arr[100005];

int main()
{
    int ca, n, k;
    int s0, s1, s2;
    bool e1, e2;
    int cnt;
    bool flag = false;

    scanf("%d", &ca);
    while(ca--)
    {
        s0 = s1 = s2 = 0;
        scanf("%d%d", &n, &k);
        scanf("%s", str);
        flag = false;
        for(int i = 0; i < n; i++)
        {
            if((str[i]-'0')%3 == 1)
            {
                arr[i] = 1;
                s1++;
            }
            else if((str[i] - '0')%3 == 2)
            {
                arr[i] = 2;
                s2++;
            }
            else
            {
                if(str[i] == '0') arr[i] = 0;
                else arr[i] = 3;
                s0++;
            }
        }
        int ans = (s1 + s2*2)%3;
        e1 = e2 = false;
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 3) break;
            if(arr[i] == 0) cnt++;
        }
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0) break;
            if(arr[i] == 1) e1 = true;
            else e2 = true;
        }

        for(int C = 0; C <= s2 && C <= k && !flag; C++)
        {
            int B = ((ans - 2*C)%3+3)%3;
            for(;B <= s1 && B+C <= k; B+=3)
            {
                int A = k - B - C;
                if(A <= s0)
                {
                    if(A >= cnt)
                    {
                        flag = true;
                        break;
                    }
                    else if(B < s1 && e1)
                    {
                        flag = true;
                        break;
                    }
                    else if(C < s2 && e2)
                    {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(n == k+1 && s0)
            printf("yes\n");
        else if(flag)
            printf("yes\n");
        else
            printf("no\n");

    }
    return 0;
}
