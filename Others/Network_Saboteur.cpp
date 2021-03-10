#include <iostream>

using namespace std;

int arr[25][25];
bool lei[25] = {0};///集合编号
int ans = 0;
int num;
void dfs(int id, int data)///递归枚举两个集合
{
    lei[id] = 1;
    int temp = data;
    for(int i = 1; i <= num; i++)
    {
        if(lei[i] == 0)
            temp += arr[id][i];
        else
            temp -= arr[id][i];
    }
    if(ans < temp)
        ans = temp;
    for(int i = id + 1; i <= num; i++)
    {
        dfs(i, temp);
        lei[i] = 0;
    }
}

int main()
{

    cin >> num;
    for(int i = 1; i <= num; i++)
        for(int j = 1; j <= num; j++)
            cin >> arr[i][j];
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
