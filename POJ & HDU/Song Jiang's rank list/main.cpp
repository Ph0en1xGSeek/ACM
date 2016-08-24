#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>


using namespace std;

bool cmp(string s1, string s2)
{
	int len = max(s1.length(), s2.length());
	for(int i = 0; i < len;i++)
	{
		if(s1[i] < s2[i]) return true;
		if(s1[i] > s2[i]) return false;
	}
	return false;
}

struct node
{
	string name;
	int num;
	bool operator<(const node& a) const
	{
		if(num == a.num)
			return cmp(name, a.name);
		return num > a.num;
	}
}arr[206];

map<string, int> mp;
map<string, int> mp2;

int main()
{
	int n, m;
	while(~scanf("%d", &n) && n != 0)
	{
		mp.clear();
		mp2.clear();
		for(int i = 1; i <= n; i++)
			cin >> arr[i].name >> arr[i].num;
		sort(arr+1, arr+n+1);
		int tmp = arr[1].num;
		int mj = 1, mi = 0;
		for(int i = 1; i <= n; i++)
		{
            if(arr[i].num != tmp)
            {
				tmp = arr[i].num;
				mj = i;
				mi = 1;
            }
            else
            {
				mi++;
            }
            mp[arr[i].name] = mj;
            mp2[arr[i].name] = mi;
		}
		for(int i = 1; i <= n; i++)
			cout << arr[i].name << ' ' << arr[i].num << endl;
		scanf("%d", &m);
		string str;
		for(int i = 0; i < m; i++)
		{
			cin >> str;
			if(mp2[str] > 1)
				printf("%d %d\n", mp[str], mp2[str]);
			else
				printf("%d\n", mp[str]);
		}
	}
    return 0;
}
