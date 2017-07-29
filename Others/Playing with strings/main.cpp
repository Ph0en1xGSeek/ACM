#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

char arr1[100010];
char arr2[100010];
int num1[30];
int num2[30];
int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",&arr1);
        scanf("%s",&arr2);
        int len1=strlen(arr1);
        int len2=strlen(arr2);
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        for(int i=0;i<len1;i++)
        {
            num1[arr1[i]-'a']++;
        }
        for(int i=0;i<len2;i++)
        {
            num2[arr2[i]-'a']++;
        }
        long long ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=abs(num2[i]-num1[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}






