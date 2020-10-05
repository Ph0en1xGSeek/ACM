#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num, ca = 1;
    char str[55];
    scanf("%d", &num);
    while(num--)
    {
        scanf("%s", str);
        printf("String #%d\n", ca++);
        for(int i = 0; str[i]; i++)
            printf("%c", 'A' + (str[i]-'A'+1)%26);
        printf("\n\n");
    }
    return 0;
}
