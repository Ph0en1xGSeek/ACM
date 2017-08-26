#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
//    char str[100];
    string str;
    getline(cin, str);
    while(str.length() > 1 || str[0] != '!')
    {
        int len = str.length();
        for(int i = 0; i < len; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = 'z' - (str[i] - 'a');
            }
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = 'Z' - (str[i] - 'A');
            }
        }
        cout << str << endl;
        getline(cin, str);
    }
    return 0;
}
