#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	char str[100010];
	int arr[100010];
	int ca;
	scanf("%d", &ca);
	while(ca--)
	{
		int sum = 0;
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < len; i++)
		{
			arr[i] = str[i] - '0';
			sum += arr[i];
		}
		sum %= 10;
		sum = 10 - sum;
		arr[len-1] += sum;
		if(arr[len-1] > 9)
		{
			int i;
			int bit = 0;
			for(i = len-2; i >= 0; i--)
			{
				bit++;
				arr[i]++;
				arr[i] %= 10;
				if(arr[i] != 0)
					break;
			}
			if(i < 0)
			{
				printf("1");
				for(i = 0; i < len-1; i++)
					printf("0");
				printf("9\n");
			}
			else
			{
				arr[len-1] = (arr[len-1] + 100000 - bit) % 10;
				for(i = 0; i < len; i++)
					printf("%d", arr[i]);
				printf("\n");
			}
		}
		else
		{
			for(int i = 0; i < len; i++)
				printf("%d", arr[i]);
			printf("\n");
		}
	}
    return 0;
}
