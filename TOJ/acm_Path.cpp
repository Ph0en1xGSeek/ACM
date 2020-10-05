#include <iostream>
#define INF 100000
using namespace std;

int arr[101][101];

int main()
{
    int n, m;
    int a, b, c;
    while(cin >> n >> m && n)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j)
                    arr[i][j] = 0;
                else
                    arr[i][j] = INF;
            }
        }

        while(m--)
        {
            cin >> a >> b >> c;
            if(a != b)
                arr[a][b] = arr[b][a] = c;
        }

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        cout << arr[1][n] << endl;
    }

    return 0;
}
