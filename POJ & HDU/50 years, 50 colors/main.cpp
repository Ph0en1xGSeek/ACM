#include<iostream>
#include <cstring>
using namespace std;

int V1,V2;
int grid[101][101];
bool vis[101];
int link[101];
int m;
bool isMark;

bool dfs(int x, int color)
{
	for(int y=1;y<=V2;y++)
		if(grid[x][y] == color && !vis[y])  //x到y相邻(有边) 且 节点y未被搜索
		{
			vis[y]=true;   //标记节点y已被搜索
			if(link[y]==0 || dfs(link[y], color)) //link[y]==0 : 如果y不属于前一个匹配M
			{                               //find(link[y] : 如果被y匹配到的节点可以寻找到增广路
				link[y]=x; //那么可以更新匹配M'(用M替代M')
				return true;  //返回匹配成功的标志
			}
		}
	return false;  //继续查找V1下一个x的邻接int main()
}

void search(int color)
{
    m = 0;
	for(int x=1;x<=V1;x++)
	{
		memset(vis,false,sizeof(vis)); //清空上次搜索时的标记
		if(dfs(x, color))  //从V1中的节点x开始寻找增广路
			m++;
	}
	return;
}


int main()
{
    int num, time;
    while(cin >> num >> time && num)
    {
        V1 = V2 = num;

        for(int i = 1; i <= num; i++)
            for(int j = 1; j <= num; j++)
                cin >> grid[i][j];
        isMark = false;
        for(int i = 1; i <= 50; i++)
        {
            memset(link,0,sizeof(link));
            search(i);
            if(m > time)
            {
                if(!isMark)
                {
                    cout << i ;
                    isMark = true;
                }
                else
                    cout << ' ' << i ;

            }
        }
        if(!isMark)
            cout << -1 << endl;
        else
            cout << endl;
    }
    return 0;
}


