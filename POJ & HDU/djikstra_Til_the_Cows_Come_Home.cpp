#include <iostream>
#define INF 1<<29

using namespace std;
int t, n;
int a, b, len;
int arr[1005][1005];

void djikstra()
{
    bool isVisted[1005];
    int d[1005];
    int min, tmp;
    for(int i =1; i <= n; i++)
    {
        isVisted[i] = 0;
        d[i] = arr[1][i];
    }
    for(int i = 1; i <= n; i++)//��1�㿪ʼҪ����n����
    {
        min = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!isVisted[j] && d[j] < min)//�ҵ�����ԭ�������û�߹��ĵ�
            {
                tmp = j;
                min = d[j];
            }
        }
        isVisted[tmp] = 1;

        for(int j = 1; j <= n; j++)//������ԭ��ľ��� ����ϵ���ݲ�����
            if(!isVisted[j] && d[j] > arr[tmp][j] + d[tmp])
                d[j] = arr[tmp][j] + d[tmp];
    }
    cout << d[n] << endl;
}


int main()
{
    cin >> t >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i==j)
                arr[i][i] = 0;
            else
                arr[i][j] = arr[j][i] = INF;
        }
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b >> len;
        if(arr[a][b] > len)
            arr[a][b] = arr[b][a] = len;
    }
    djikstra();
    return 0;
}
