#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX 202
#define inf 10086

using namespace std;
int mat[MAX][MAX], vis[MAX], dist[MAX];
char name[MAX][31];
int n, m, num, s, t;

int djisktra()
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    dist[s] = inf;
    for(int i = 0; i < n-1; i++)
    {
	int tmp = 0, v;
	for(int j = 0; j < n; j++)
	    if(!vis[j] && dist[j] > tmp)
		tmp = dist[v = j];
	vis[v] = 1;
	for(int j = 0; j < n; j++)
	    if(!vis[j])
		dist[j] = max(min(mat[v][j], dist[v]), dist[j]);
    }
    return dist[t];
}

int getCity(char s[])
{
    int u = -1;
    for(int i = 0; i < num; i++)
	if(!strcmp(name[i], s))
	    {u = i; break;}
    return u;
}

int main(int argc, char **argv)
{
	int cnt = 1;
	num = 0;
	char s1[31], s2[21];
	while(scanf("%d%d", &n, &m) != EOF && (n  && m))
	{
		num = 0;
		memset(mat, 0, sizeof(mat));
		for(int i = 0; i < m; i++)
		{
		    int u, v, d;
		    scanf("%s%s%d", s1, s2, &d);
		    u = getCity(s1);
		    if(u == -1)
		    {
			u = num++;
			strcpy(name[u], s1);
		    }
		    v = getCity(s2);
		    if(v == -1)
		    {
			v = num++;
			strcpy(name[v], s2);
		    }
		    mat[u][v] = mat[v][u] = d;
		}
		scanf("%s%s", s1,s2);
		s = getCity(s1);
		t = getCity(s2);
		printf("Scenario #%d\n", cnt++);
		printf("%d tons\n\n", djisktra());
	}
	return 0;
}
