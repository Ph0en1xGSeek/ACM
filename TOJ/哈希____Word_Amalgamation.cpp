#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;
set<string> hx[7];

int main()
{
    int is;
    string str;
    while(cin >> str && str != "XXXXXX")
    {
        int len = str.length();
        hx[len].insert(str);
    }
    string arr[7][100];
    string tmp[7][100];
    for(int i = 1; i <= 6; i++)
    {
        int j = 0;
        for(set<string>::iterator it = hx[i].begin(); it != hx[i].end(); it++)
        {
            arr[i][j] = *it;
            tmp[i][j] = *it;
            sort(&arr[i][j][0], &arr[i][j][arr[i][j].length()]);
            j++;
        }
    }
    while(cin >> str && str != "XXXXXX")
    {
        is = 0;
        int len = str.length();
        sort(&str[0], &str[len]);
        for(int i = 0; i < hx[len].size(); i++)
            if(str == arr[len][i])
            {
                cout << tmp[len][i] << endl;
                is = 1;
            }
        if(!is)
            cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
    return 0;
}
