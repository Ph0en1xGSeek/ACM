#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using  namespace std;

map<char, char> mp;

int main() {

    string s, t;
    string typeStr;
    char arr[1000];
    cin >> s >> t;
    for(int i = 0; i < 26; i++)
    {
        mp[s[i]] = t[i];
    }

    cin >> typeStr;
    for(int i = 0; i < typeStr.length(); i++)
    {
        if(typeStr[i] >= '0' && typeStr[i] <= '9')
        {
            arr[i] = typeStr[i];
        }
        else if(typeStr[i] >= 'a' && typeStr[i] <= 'z')
        {
            arr[i] = mp[typeStr[i]];
        }
        else if(typeStr[i] >= 'A' && typeStr[i] <= 'Z')
        {
            arr[i] = mp[typeStr[i] - 'A' + 'a'] - 'a' + 'A';
        }
    }
    arr[typeStr.length()] = '\0';
    printf("%s\n", arr);
    return 0;
}