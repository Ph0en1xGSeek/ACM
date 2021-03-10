#include <iostream>
#include <stdio.h>
#include <string.h>
#define M 40000
#define N 5000

using namespace std;

int prime[N] = {0};
int isP[M] = {0};
int cnt = 0;

void getprime()
{
    for(int i = 2; i < M; i++)
    {
        if(isP[i] == 0)
        {
            for(int j = 2*i; j < M; j+=i)
                isP[j] = 1;
            prime[cnt++] = i;
        }
    }
}

int main()
{
    getprime();
    int num;
    while(scanf("%d", &num), num)
    {
        cnt = 0;
        for(int i = 0; prime[i] <= num/2; i++)
            if(isP[num-prime[i]] == 0)
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
