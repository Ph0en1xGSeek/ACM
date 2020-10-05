#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int p, q;

int dfs(int cur, int step, int stop)///����λ�ã����߲�����ͣ�ٴ���
{
    int cnt = 0;
    while(cur - (1<<cnt) + 1 > q) cnt++;
    step += cnt;
    if(cur - (1<<cnt) + 1 == q) return step;
    int up = q - max(0, cur - (1<<cnt) + 1);///��Ҫ�����߶��ٲ�
    int tmp = step + max(up-stop, 0);///ͨ����֮ǰ��ͣ�ٻ�������һ��������֮�����ϵĲ���
    return min(tmp, dfs(cur - (1<<(cnt-1))+1, step, stop + 1));
}

int main()
{
    int ca;
    int ans;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &p, &q);
        if(p <= q)
            ans = q - p;
        else
            ans = dfs(p, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
