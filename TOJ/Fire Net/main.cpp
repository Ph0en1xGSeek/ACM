#include <iostream>
#include <cstring>

using namespace std;
int arr[6][6];//0Ç½£¬1Â·£¬2Ëþ
int num;

bool isok(int x, int y)
{
    if(arr[x][y] != 1)
        return false;
    int tx = x+1, ty = y;
    while(arr[tx][ty] != 0)
        if(arr[tx++][ty] == 2)
            return false;
    tx = x-1, ty = y;
    while(arr[tx][ty] != 0)
        if(arr[tx--][ty] == 2)
            return false;
    tx = x, ty = y+1;
    while(arr[tx][ty] != 0)
        if(arr[tx][ty++] == 2)
            return false;
    tx = x, ty = y-1;
    while(arr[tx][ty] != 0)
        if(arr[tx][ty--] == 2)
            return false;
    return true;
}

int dfs(int x, int y, int deep)
{
    int tmp = deep;
    int tx = x, ty = y;
    ty++;
    if(ty > num)
    {
        tx++;
        ty = 1;
    }
    while(tx != num + 1)
    {
        if(isok(tx, ty))
        {
            arr[tx][ty] = 2;
            tmp = max(tmp, dfs(tx, ty, deep+1));
            arr[tx][ty] = 1;
        }
        ty++;
        if(ty > num)
        {
            tx++;
            ty = 1;
        }
    }
    return tmp;
}

int main()
{
    char ch;
    int ans;
    while(cin >> num, num)
    {
        ans = 0;
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= num; i++)
        {
            for(int j = 1; j <= num; j++)
            {
                cin >> ch;
                if(ch == '.')
                    arr[i][j] = 1;
            }
        }
        for(int i = 1; i <= num; i++)
        {
            for(int j = 1; j <= num; j++)
            {
                if(isok(i, j))
                {
                    arr[i][j] = 2;
                    ans = max(ans, dfs(i, j, 1));
                    arr[i][j] = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
