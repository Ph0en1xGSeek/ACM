#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

string str;
string tmp = "anniversary";

int cal(int len)
{
	for(int i = 1; i+2 <= tmp.length(); i++)
	{
		int s1 = str.find(tmp.substr(0, i), 0);
		if(s1 < 0) continue;
		for(int j = 1; i+j+1 <= tmp.length(); j++)
		{
			int s2 = str.find(tmp.substr(i, j), s1+i);
			if(s2 < 0) continue;

			int k = tmp.length()-i-j;
			if(str.find(tmp.substr(i+j, k), s2+j) < 200)
			return true;
		}
	}
	return false;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
		cin >> str;
		if(cal(str.length()))
			puts("YES");
		else
			puts("NO");
    }
    return 0;
}
