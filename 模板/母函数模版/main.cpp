#include <iostream>
using namespace std;
//�˳���Ϊ��һ�������ֽ�Ϊ������������ķ���

const int N=120;
int f[N+1],a[N+1],g[N+1];
int i,j,k,n,m;

int main()
{
    while(cin>>n)
    {
        for (i = 0; i <= n; ++i) // 0 1 2 3 4 5 6
            f[i]=1;

        for (i = 2; i <= n; ++i) // f[]����ǰ��i-1��������˵Ľ�� i = 1�����ѭ����ʼ������
        {
            for (j = 0; j <= n; ++j)
                a[j]=0;
            j=0;
            while (j <= n)   // a[j]=k��ʾ����k*(x^j),a[]�����ʾĸ�����ĵ�i������
            {
                a[j]=1;
                j+=i;// * (0 2 4 6 8) * (0 3 6 9 12) * (0 4 8 12)
            }

            for (j = 0; j <= n; ++j) // �ݴ�f[]*a[]�Ľ��
                g[j] = 0;

            for (j = 0; j <= n; ++j)
                for(k = 0; k+j <= n; ++k)
                    g[j+k] += f[j]*a[k]; // Ϊ�˲���f[]��ֵ��Ϊ�Ķ���Ӱ���Ժ��ֵ����g[]���ݴ���
                //j�η���k�η���˸ı�j+k�η�ϵ��                        // ����ĸ������������ˣ���f[j]��a[k]�ֱ����ڵ�1��2�����ӣ���ôf[j]*(x^j)*a[k]*(x^k)==f[j]*a[k]*(x^(j+k))
                                        // ����g[j+k]+=f[j]*a[k]
            for (j = 0; j <= n; ++j)
                f[j] = g[j];
        }
        cout<<f[n]<<endl;
    }
    return 0;
}
