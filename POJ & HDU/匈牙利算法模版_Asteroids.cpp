
#include<iostream>
#include <cstring>
using namespace std;

int n,k;  //n������k��������
int V1,V2;       //����ͼ���㼯
 /*��������зֱ����ڶ���ͼ���������㼯V1��V2��������x��V1����y��V2*/
bool grid[501][501];  //�洢���ݷ�ʽ���ɴ����
bool vis[501];     //��¼V2�ĵ�ÿ�����Ƿ��ѱ�������
int link[501];     //��¼ V2�еĵ�y �� V1�� ��ƥ��ĵ�x�ı��
int m;  //���ƥ����

bool dfs(int x)
{
	for(int y=1;y<=V2;y++)
		if(grid[x][y] && !vis[y])  //x��y����(�б�) �� �ڵ�yδ������
		{
			vis[y]=true;   //��ǽڵ�y�ѱ�����
			if(link[y]==0 || dfs(link[y])) //link[y]==0 : ���y������ǰһ��ƥ��M
			{                               //find(link[y] : �����yƥ�䵽�Ľڵ����Ѱ�ҵ�����·
				link[y]=x; //��ô���Ը���ƥ��M'(��M���M')
				return true;  //����ƥ��ɹ��ı�־
			}
		}
	return false;  //��������V1��һ��x���ڽӽڵ�
}

void search(void)
{
	for(int x=1;x<=V1;x++)
	{
		memset(vis,false,sizeof(vis)); //����ϴ�����ʱ�ı��
		if(dfs(x))  //��V1�еĽڵ�x��ʼѰ������·
			m++;
	}
	return;
}

int main(void)
{
	cin>>n>>k;
	V1=V2=n;

	int x,y;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		grid[x][y]=true;   //���ڽڵ���
	}

	/*���������*/

	search();

	cout<<m<<endl;

	return 0;
}
