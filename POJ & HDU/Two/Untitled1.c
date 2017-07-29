#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int tmp_deep;
char ts[20];
char in[20];
bool flag;

int mov[8][4]={{1,2,5,4},{2,3,6,5},{4,5,8,7},{5,6,9,8},{4,5,2,1},{5,6,3,2},{7,8,5,4},{8,9,6,5}};

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

int get_way(char arr[])
{
    int ans=0;
    for(int i=0;i<9;i++)
    {
        int tmp=arr[i]-'0';
        ans+=(abs((tmp-1)/3-i/3)+abs((tmp-1)%3-i%3));
    }
    return (ans+3)/4;
}

void dfs(char arr[],int deep)
{
    if(flag)
        return;
    if(deep+get_way(arr)>tmp_deep)
        return;
    if(get_way(arr)==0)
    {
        flag=true;
        return;
    }
    for(int i=0;i<8;i++)
    {
        for(int t=0;t<=9;t++)
            ts[t]=arr[t];
        int tmp=ts[mov[i][0]-1];
        for(int t=0;t<3;t++)
        {
            ts[mov[i][t]-1]=ts[mov[i][t+1]-1];
        }
        ts[mov[i][3]-1]=tmp;
        dfs(ts,deep+1);
    }
    return;
}

int main()
{
    int num=0;
    char x;
    while(scanf("%s",&in)!=EOF)
    {
        num++;
        if(in[0]=='0'&&in[1]=='0')
            break;
        x=in[0];
        for(int i=0;i<=9;i++)
            in[i]=in[i+1];
        bool ans=false;
        int tim=x-'0';
        int i;
        for(i=0;i<=tim;i++)
        {
            tmp_deep=i;
            flag=false;
            dfs(in,0);
            if(flag)
            {
                ans=true;
                break;
            }
        }
        cout<<num<<". ";
        if(ans)
            cout<<i<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}



















