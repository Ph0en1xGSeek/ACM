#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int s, v1, v2, p1, p2;
    while(~scanf("%d%d%d%d%d", &s, &v1, &v2, &p1, &p2))
    {
        int ans1 = v1*s + p1*2;
        int ans2 = v2*s + p2*2;
        if(ans1 < ans2) printf("First\n");
        else if(ans1 > ans2) printf("Second\n");
        else printf("Friendship\n");
    }
    return 0;
}
