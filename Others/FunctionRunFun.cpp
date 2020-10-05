#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int arr[22][22][22] ;

int main(int argc, char **argv)
{
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < 21; i++)
	    for(int j = 0; j < 21; j++)
		arr[0][i][j] = arr[i][0][j] = arr[i][j][0] = 1;
	for(int i = 1; i < 21; i++)
	    for(int j = 1; j < 21; j++)
		for(int k = 1; k < 21; k++)
		    if(i < j && j < k)	arr[i][j][k] = arr[i][j][k-1] + arr[i][j-1][k-1] - arr[i][j-1][k];
		    else 	arr[i][j][k] = arr[i-1][j][k] + arr[i-1][j-1][k] + arr[i-1][j][k-1] - arr[i-1][j-1][k-1];
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) )
	{
	    if(a == -1 && (b == -1 && c == -1))	break;
	    if(a <= 0 || b <= 0 || c <= 0)	printf("w(%d, %d, %d) = 1\n", a, b, c);
	    else if(a > 20 || b > 20 || c > 20)	printf("w(%d, %d, %d) = 1048576\n", a, b, c);
	    else printf("w(%d, %d, %d) = %d\n", a, b, c, arr[a][b][c]);
	}
	return 0;
}
