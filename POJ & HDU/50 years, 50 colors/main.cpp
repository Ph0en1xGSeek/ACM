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
		if(grid[x][y] == color && !vis[y])  //x��y����(�б�) �� �ڵ�yδ������
		{
			vis[y]=true;   //��ǽڵ�y�ѱ�����
			if(link[y]==0 || dfs(link[y], color)) //link[y]==0 : ���y������ǰһ��ƥ��M
			{                               //find(link[y] : �����yƥ�䵽�Ľڵ����Ѱ�ҵ�����·
				link[y]=x; //��ô���Ը���ƥ��M'(��M���M')
				return true;  //����ƥ��ɹ��ı�־
			}
		}
	return false;  //��������V1��һ��x���ڽ�int main()
}

void search(int color)
{
    m = 0;
	for(int x=1;x<=V1;x++)
	{
		memset(vis,false,sizeof(vis)); //����ϴ�����ʱ�ı��
		if(dfs(x, color))  //��V1�еĽڵ�x��ʼѰ������·
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


