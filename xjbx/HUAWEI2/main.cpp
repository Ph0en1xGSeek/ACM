#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
#define M 600
#define INF 1<<30

using namespace std;

int arr[M][M];
int matrix[M][M];
int V[M] = {0};
int checkV[M];
int ss[M];
int top;
int from[M];
bool isVisted[M + 1];
int in[M] = {0};

bool check(int num)
{
    for(int i = 0; i < num; i++)
        if(V[i] == 1 && checkV[i] == 0)
            return false;
    return true;
}

bool djikstra(int s, int t, int num, int deep)
{
    if(deep == 50)
        return 0;
    int i, u, v;
    memset(isVisted, 0, sizeof(isVisted));
    isVisted[s] = 1;
    int d[M];
    int mini, tmp;
    for(i = 0; i < num; i++)
    {
        d[i] = arr[s][i];
        if(d[i] < INF)
            from[i] = s;
    }
    for(i = 0; i < num - 1; i++)
    {
        tmp = M;
        mini = INF;
        for(int j = 0; j < num; j++)
        {
            if(!isVisted[j] && d[j] < mini)
            {
                tmp = j;
                mini = d[j];
            }
        }
        if(tmp == M || tmp == t)
            break;
        isVisted[tmp] = 1;
        for(int j = 0; j <num; j++)
        if(!isVisted[j] && (d[j] > arr[tmp][j] + d[tmp] && arr[tmp][j] != INF))
	    {
            from[j] = tmp;
            d[j] = arr[tmp][j] + d[tmp];
	    }
    }
    if(tmp == M || d[t] == INF)
        return 0;
    memset(checkV, 0, sizeof(checkV));
    top = 0;
    while(tmp != s)
    {
        ss[top++] = matrix[from[tmp]][tmp];
        checkV[from[tmp]] = 1;
        if(in[tmp] > 1 && !V[tmp])
        {
            u = from[tmp];
            v = tmp;
        }
        tmp = from[tmp];
    }
    if(check(num))
        return 1;
    else
    {
        arr[u][v] = INF;
        return djikstra(s, t, num, deep+1);
    }
}

int main(int argc, char **argv)
{
	int a, b, c, d;
	int s, t, num = 0, numV = 0;
	char tmp;
	for(int i = 0; i  < M; i++)
	    for(int j = 0; j < M; j++)
            arr[i][j] = INF;
	while(scanf("%d,%d,%d,%d", &a, &b, &c, &d) != EOF)
	{
	    if(d < arr[b][c])
	    {
            matrix[b][c] = a;
            arr[b][c] = d;
            in[c]++;
	    }
	    num = max(num, b);
	    num = max(num, c);
	}
	num++;
	scanf("%d, %d,", &s, &t);
	while(scanf("%d%c", &d, &tmp) && tmp == '|')
	{
	    numV++;
	    V[d] = 1;
	}
	numV++;
	V[d] = 1;


	for(int i = 0; i < num; i++)
	    if(!V[i])
        {
            if(i != t)
            {

                int cnt = 0;
                for(int j = 0; j < num; j++)
                    if(V[j] && arr[i][j] < INF)
                        cnt++;
                for(int j = 0; j < num; j++)
                    if(arr[j][i] < INF)
                    {
                        arr[j][i] -= 20;
                        arr[j][i] *= cnt;
                    }
            }
        }
        else
        {
            for(int  j = 0; j < num; j++)
            {
                if(arr[j][i] < INF)
                {
                    arr[j][i] -= 20;
                    arr[j][i] <<= 9;
                }
            }
        }

    for(int  j = 0; j < num; j++)
    {
        if(arr[j][t] < INF)
        {
            arr[j][t] += 10;
            arr[j][t] <<= 7;
        }
        if(j == s && arr[s][t] < INF)
            arr[j][t] <<= 6;
    }



	if(djikstra(s, t, num, 0))
    {
        printf("%d", ss[--top]);
        while(top > 0)
        {
            printf("|%d", ss[--top]);
        }
        printf("\n");
    }
	else
    {
        printf("NA\n");
    }
	return 0;
}
