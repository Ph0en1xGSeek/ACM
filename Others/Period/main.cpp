#include <iostream>
#include <stdio.h>

using namespace std;
char t[1000010];
int nex[1000010];
int m;

void getnext()
{
    int i = 0;
    int j = -1;
    nex[0] = -1;
    while(i < m)
    {
        if(j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            nex[i] = j;
        }
        else
            j = nex[j];
    }
}

int main()
{
    int ca = 1;
    while(cin >> m && m)
    {
        scanf("%s", t);
        getnext();
        printf("Test case #%d\n", ca++);
        for(int i = 2; i <= m; i++)
        {
            if(i/ (i - nex[i]) > 1 && i % (i - nex[i]) == 0)
                cout << i << ' ' << i/ (i - nex[i]) << endl;
        }
        cout << endl;
    }
    return 0;
}
