#include <iostream>
#include <algorithm>
using namespace std;
int num;

struct rectangle
{
    int x, y, z;
}brick[100];

int dp[100];//第i块砖头为顶时能有多高

bool cmp(rectangle a, rectangle b)
{
    if(a.x == b.x)
        return a.y > b.y;
    else
        return a.x > b.x;
}

int Dp()
{
    int highest = 0;
    sort(brick, brick + num, cmp);
    for(int i = 0; i < num; i++)
    {
        dp[i] = brick[i].z;
        for(int j = i - 1; j >= 0; j--)
        {
            if(brick[j].x > brick[i].x && brick[j].y > brick[i].y)
                dp[i] = max(dp[j] + brick[i].z, dp[i]);
        }
        if(dp[i] > highest)
            highest = dp[i];
    }
    return highest;
}
int main()
{
    int i, j,ca = 1,a,b,c;
    while(cin >> num && num)
    {
        for(j = 0, i = 0;i < num;i++)
        {
              cin >> a >> b >> c;
              brick[j].x = min(a,b);
              brick[j].y = max(a,b);
              brick[j].z = c;
              brick[j+1].x = min(a,c);
              brick[j+1].y = max(a,c);
              brick[j+1].z = b;
              brick[j+2].x = min(c,b);
              brick[j+2].y = max(c,b);
              brick[j+2].z = a;
              j += 3;
        }

        num = j;
        cout << "Case " << ca++ << ": maximum height = " << Dp() << endl;
    }
    return 0;
}
