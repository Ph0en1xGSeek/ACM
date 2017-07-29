#include <iostream>
#include <cstring>

using namespace std;
bool arr[10][10], col[10];
int n, k, hang, ans;

void dfs(int k)
{
    if(k == 0)
    {
        ans++;
        return;
    }
    if(hang >= n || k > (n - hang))
        return;
    hang++;
    for(int i = 1; i <= n; i++)
    {
        if(!arr[hang][i] || col[i])
            continue;
        col[i] = 1;
        dfs(k - 1);
        col[i] = 0;
    }
    dfs(k);
    if(hang > 1)
        hang--;
    return;
}

int main()
{

    char ch;
    while(cin >> n >> k && n != -1)
    {
        hang = 0;
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(col, 0, sizeof(col));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> ch;
                if(ch == '#')
                    arr[i][j] = 1;
            }
        }
        dfs(k);
        cout << ans << endl;
    }
    return 0;
}
