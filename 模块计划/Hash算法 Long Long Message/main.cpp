#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 100010

using namespace std;

typedef unsigned long long ull;
int ls1, ls2, l, r;
char s1[N], s2[N];
ull h1[N], h2[N], pow[N], a[N];

inline ull getHash(ull h[], int i, int j)
{
	return h[j] - h[i]*pow[j-i];
}

bool haveSolution(int t)
{
	int cnt = 0;
	for(int i = t; i <= ls1; i++)
		a[cnt++] = getHash(h1, i-t, i);
	sort(a, a+cnt);
	for(int i = t; i <= ls2; i++)
	{
		ull tmp = getHash(h2, i-t, i);
		if(binary_search(a, a+cnt, tmp))
		  return true;
	}
	return false;
}

void init()
{
	l = 0, r = max(ls1, ls2);
	pow[0] = 1;
	for(int i = 1; i <= r; i++)
        pow[i] = pow[i-1]*131;
	h1[0] = 0;
	for(int i = 0; i < ls1; i++)
        h1[i+1] = h1[i]*131 + s1[i];
	h2[0] = 0;
	for(int i = 0; i < ls2; i++)
		h2[i+1] = h2[i]*131 + s2[i];
}

int main()
{
    while(~scanf("%s %s", s1, s2)){
		ls1 = strlen(s1);
		ls2 = strlen(s2);
		init();
		while(l != r)
		{
			int mid = (l+r) >> 1;
			if(haveSolution(mid+1))
			  l = mid+1;
			else
			  r = mid;
		}
		printf("%d\n", l);
	}
    return 0;
}
