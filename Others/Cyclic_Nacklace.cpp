#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int nex[100110];
char t[100110];



void getnext(int m)
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
    int m;
    int ca;
    int cir;
    cin >> ca;
    while(ca--)
    {
        gets(t);
        memset(nex, 0, sizeof(nex));
        m = strlen(t);
        getnext(m);
        cir = m - nex[m];
        if(cir != m && m % cir == 0)
            cout << 0 << endl;
        else
            cout << cir - nex[m] % cir << endl;
    }
    return 0;
}
