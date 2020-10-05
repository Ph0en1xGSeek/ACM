#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    string str1 = "MAI MAI MAI!", str2 = "SONY DAFA IS GOOD!";
    char str[10000];
    while(~scanf("%s", str))
    {
		int len = strlen(str);
		for(int i = 0; i < len; i++)
		{
			if(str[i] == 'A' && str[i+1] == 'p' && str[i+2] == 'p' && str[i+3] == 'l' && str[i+4] == 'e')
				cout << str1 << endl;
			if(str[i] == 'i' && str[i+1] == 'P' && str[i+2] == 'h' && str[i+3] == 'o' && str[i+4] == 'n' && str[i+5] == 'e')
				cout << str1 << endl;
			if(str[i] == 'i' && str[i+1] == 'P' && str[i+2] == 'o' && str[i+3] == 'd')
				cout << str1 << endl;
			if(str[i] == 'i' && str[i+1] == 'P' && str[i+2] == 'a' && str[i+3] == 'd')
				cout << str1 << endl;
			if(str[i] == 'S' && str[i+1] == 'o' && str[i+2] == 'n' && str[i+3] == 'y')
				cout << str2 << endl;
		}
    }
    return 0;
}
