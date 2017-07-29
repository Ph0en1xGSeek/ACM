#include <stdio.h>

using namespace std;

int main()
{
    int num, tmp, ans;
    while(scanf("%d", &num), num)
    {
        ans = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &tmp);
            ans  = (ans ^ tmp);
        }
        if(ans == 0)
            printf("Grass Win!\n");
        else
            printf("Rabbit Win!\n");

    }
    return 0;
}
