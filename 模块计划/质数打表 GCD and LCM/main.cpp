#include <iostream>
#define MAXN 50000

using namespace std;

int arrp[MAXN];//用来存质数的
int vis[MAXN];//标记
int k;
void get_prime()
{
	k = 0;
	vis[2] = 0;
	for(int i = 2; i < MAXN; i++)
	{
		if(!vis[i])
		{
			arrp[k++] = i;
			for(int j = i; j < MAXN; j += i)
                vis[j]=1;
		}
	}
}

int main()
{
    get_prime();
    int ca, g, l;
    cin >> ca;
    while(ca--)
    {
        cin >> g >> l;
        if(l % g)
        {
            cout << 0 << endl;
            continue;
        }
        int tmp = l / g;
        int num, ans = 1;
        for(int i = 0; i < k; i++)
        {
            if(tmp % arrp[i])
                continue;
            if(arrp[i] * arrp[i] > tmp)
                break;
            num = 0;
            while(tmp % arrp[i] == 0)
            {
                tmp /= arrp[i];
                num++;
            }
            ans *= 3 + 3 + 3 * 2 * (num - 1);
        }
        if(tmp > 1)//质数分解后剩下一个质数 或这个数本身就是一个质数
            ans *= 6;
        cout << ans << endl;
    }
    return 0;
}
