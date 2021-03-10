#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 50005

using namespace std;

struct node
{
    long long pos;
    int flag;
    long long src;
    bool operator<(const node& b) const
    {
        if(pos == b.pos) return flag < b.flag;
        return pos < b.pos;
    }
}arr[M*3];

int main()
{
    int ca, num;
    long long ans = 0;
    long long tmp;
    long long l, r, a, b, c;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%I64d%I64d%I64d%I64d%I64d", &l, &r, &a, &b, &c);
            arr[i<<1].pos = l;
            arr[i<<1].flag = 0;
            arr[i<<1].src = -c+a;
            arr[(i<<1)+1].pos = r;
            arr[(i<<1)+1].flag = 1;
            arr[(i<<1)+1].src = -a+b;

            ans += c;
        }
        tmp = ans;

        sort(arr, arr+(num<<1));
        for(int i = 0 ; i < (num<<1); i++)
        {

            if(arr[i].flag == 0)
            {
                int j = i;
                do
                {
                    tmp += arr[j].src;
                    j++;
                }while(j < (num<<1) && (arr[j].pos == arr[i].pos && arr[j].flag == 0));
                i = j-1;
            }
            else
            {
                int j = i;
                do
                {
                    tmp += arr[j].src;
                    j++;
                }while(j < (num<<1) && (arr[j].pos == arr[i].pos && arr[j].flag == 1));
                i = j-1;
            }
            ans = max(ans, tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
