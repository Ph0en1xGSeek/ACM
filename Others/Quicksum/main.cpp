#include <iostream>
#include "stdio.h"
#include "string.h"
#include "ctype.h"using namespace std;
using namespace std;

int main()
{
    char ch[255];
    int total;
    while(gets(ch) &&ch[0]!='#')
    {
        total = 0;
        for(int i = 0; i < strlen(ch); i++)
        {
            if(ch[i] == ' ')
                continue;
            else
                total += (ch[i] - 'A' + 1)* (i+1);
        }
        cout << total << endl;
    }
    return 0;
}
