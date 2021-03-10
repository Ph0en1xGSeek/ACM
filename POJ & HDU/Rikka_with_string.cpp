#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool flag;
int len;
char str[1005];

bool judge()
{
	for(int i = 0; i <= len/2; i++)
	{
		if(str[i] != str[len-1-i])
			return false;
	}
	return true;
}

void dfs(int x)
{
	if(flag) return;
	if(x == len)
	{
		if(!judge())
		{
			printf("%s\n", str);
			flag = true;
		}
		return;
	}
	if(str[x] >= 'a' && str[x] <= 'z')
	{
		dfs(x+1);
		return;
	}
	if(str[x] == '?')
	{
		for(int i = 'a'; i <= 'z'; i++)
		{
			str[x] = (char)i;
			dfs(x+1);
            str[x] = '?';
		}
	}
}

int main()
{
    while(~scanf("%d", &len))
    {
		flag = false;
		scanf("%s", str);
		dfs(0);
		if(flag == false)
			printf("QwQ\n");
    }
    return 0;
}
