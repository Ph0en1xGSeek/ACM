#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char dna[105];
    char rna[105];
    int t, n, flag;
    scanf("%d", &t);
    while(t--)
    {
        flag = 1;
        scanf("%d", &n);
        scanf("%s", dna);
        scanf("%s", rna);
        for(int i = 0; i < n; i++)
        {
            if(dna[i] == 'A' && rna[i] != 'U')
            {
                flag = 0;
                break;
            }
            if(dna[i] == 'C' && rna[i] != 'G')
            {
                flag = 0;
                break;
            }
            if(dna[i] == 'G' && rna[i] != 'C')
            {
                flag = 0;
                break;
            }
            if(dna[i] == 'T' && rna[i] != 'A')
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
