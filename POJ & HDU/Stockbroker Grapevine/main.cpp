#include <iostream>
#include <cstring>
#define INF 100000

using namespace std;
int arr[105][105];

int main()
{
    int num, n, a, b, p;
    int mx, ans;
    while(cin >> num && num)
    {
        for(int i = 1; i <= num; i++)
            for(int j = 1; j <= num; j++)
            {
                if(i != j)
                    arr[i][j] = INF;
                else
                    arr[i][i] = 0;
            }
        for(int i = 1; i <= num; i++)
        {
            cin >> n;
            for(int j = 0; j < n; j++)
            {
                cin >> a >> b ;
                arr[i][a] = b;
            }
        }
        for(int k = 1; k <= num; k++)
            for(int i = 1; i <= num; i++)
                for(int j = 1; j <= num; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        ans = INF;
        for(int i = 1; i <= num; i++)
        {
            mx = 0;
            for(int j = 1; j <= num; j++)
            {
                mx = max(mx, arr[i][j]);
            }

            if(mx < ans)
            {
                ans = mx;
                p = i;
            }
        }
        cout << p << ' ' << ans << endl;
    }
    return 0;
}
