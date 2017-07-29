#include <stdio.h>
#include <stdlib.h>
#define MAX 250

int main()
{
    int arr[MAX];
    int total, num;
    while(scanf("%d%d", &total, &num) != EOF)
    {
        int i, pos = 0;
        for(i = 0; i < total; i++)
            arr[i] = i+1;
        for(i = total; i > 1; i--)
        {
            pos = (pos + num - 1) % i;
            printf("%d ", arr[pos]);
            int j;
            for(j = pos; j < i-1; j++)
                arr[j] = arr[j+1];
        }
        printf("%d\n", arr[0]);

    }
    return 0;
}
