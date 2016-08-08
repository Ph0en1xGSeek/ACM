#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        cout << str;
        for(int i = str.length()-1; i >= 0; i--)
            cout << str[i];
        cout << endl;
    }
    return 0;
}
