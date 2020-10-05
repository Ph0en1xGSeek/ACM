#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

//int sg[10010];
//bool vis[10010];
///以下是打表 其实就是普通NIm 没影响
//void SG()
//{
//	sg[0] = 0;
//	sg[1] = 1;
//	sg[2] = 2;
//	sg[3] = 3;
//	for(int i = 4; i <= 1000; i++)
//	{
//		memset(vis, false, sizeof(vis));
//		for(int j = 0; j < i; j++)
//		{
//			vis[sg[j]] = true;
//			for(int k = 1; k <= j/2; k++)
//			{
//				vis[sg[k]^sg[j-k]] = true;
//			}
//		}
//		int p = 0;
//		while(vis[p] == true)
//			p++;
//		sg[i] = p;
//	}
//}

int main()
{
	//SG();
    int num;
    while(~scanf("%d", &num))
    {
		int tmp;
		int ans = 0;
		for(int i = 0; i < num; i++)
		{
			scanf("%d", &tmp);
			ans ^= tmp;
		}
		if(ans != 0) puts("Win");
		else puts("Lose");
    }
    return 0;
}
