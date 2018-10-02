#include <iostream>
#include <cstring>
#define INF 2015

using namespace std;

int arr[201][201];


int main()
{
    int n, m, a, b, len, K;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)//Ԥ����
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    arr[i][j] = 0;
                else
                    arr[i][j] = INF;
            }
        }
        cin >> m;
        while(m--)
        {
            cin >> a >> b >> len;
            //if(len < arr[a][b])
            //{
                arr[a][b] = len;
                arr[b][a] = len;
            //}

        }

        for(int k = 0; k < n; k++)//Floyd n^3
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
        cin >> K;
        int point;
        for(int i = 0; i <= K; i++)//��һ���ҵ�����0������Ҫ��k+1��
        {
            int ans = INF - 2;
            for(int j = 0 ; j < n; j++)
            {
                if(ans > arr[0][j])
                {
                    ans = arr[0][j];
                    point = j;
                }
            }
            arr[0][point] = INF;
        }
        cout << point << endl;

    }

    return 0;
}
