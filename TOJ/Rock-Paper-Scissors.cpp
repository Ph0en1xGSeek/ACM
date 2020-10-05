#include <iostream>
#include <cstdio>

using namespace std;
int arr[55][55];

int main()
{
    int r, num, tmp, ans, tot, mx;
    char ch;
    while(scanf("%d", &r)!= EOF)
    {
        tot = 0;
        mx = 0;
        for(int i = 0 ;i < r; i++)
        {
            cin >> ch;
            if(ch == 'R')
                arr[0][i] = 1;
            else if(ch == 'S')
                arr[0][i] = 0;
            else if(ch == 'P')
                arr[0][i] = -1;
        }
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
        {
            for(int j = 0; j < r; j++)
            {
                cin >> ch;
                if(ch == 'R')
                    arr[i][j] = 1;
                else if(ch == 'S')
                    arr[i][j] = 0;
                else if(ch == 'P')
                    arr[i][j] = -1;
            }
        }
        for(int i = 0; i < r; i++)
        {
            tmp = 0;
            for(int j = -1; j <= 1; j++)
            {
                ans = 0;
                for(int k = 1; k <= num; k++)
                {
                    ans += (j-arr[k][i]+4)%3;
                }
                tmp = max(tmp, ans);
                if(j == arr[0][i])
                    tot += ans;
            }
            mx += tmp;
        }
        printf("%d\n%d\n", tot, mx);
    }
    return 0;
}
