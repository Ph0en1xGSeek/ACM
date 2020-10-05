#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 2010;
int father[MAX<<1];

int getFather(int n)
{
    if(father[n] == 0)
        return n;
    return father[n] = getFather(father[n]);
}

void unions(int a, int b)
{
    a = getFather(a);
    b = getFather(b);
    if(a != b)
        father[a] = b;
}

int main()
{
    int num;
    int m, n;
    int w = 1;
    scanf("%d", &num);

    while(num--)
    {
        memset(father, 0, sizeof(father));
        scanf("%d%d", &m, &n);
        bool isGay = false;
        while(n--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            unions(a, b + m);
            unions(b, a + m);
            if(getFather(a) == getFather(a + m) || getFather(b) == getFather(b + m))
            {
                isGay = true;
            }
        }
        printf("Scenario #%d:\n", w++);
        printf("%s\n\n", isGay ? "Suspicious bugs found!" : "No suspicious bugs found!");
    }
    return 0;
}
