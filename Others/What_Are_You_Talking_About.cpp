#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{

    map<string, string> m;
    m.clear();
    char ch;
    string str1, str2;
    cin >> str1;
    while(cin >> str1 && str1 != "END")
    {
        cin >> str2;
        m[str2] = str1;
    }
    ch = getchar();
    cin >> ch;
    str1 = "";
    while(1)
    {
        while(1)
        {
            scanf("%c", &ch);
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                str1 += ch;
            else
                break;
        }
        if(str1 == "END")
            break;
        if(m.find(str1) == m.end())
            cout << str1;
        else
            cout << m[str1];
        str1 = "";
        printf("%c", ch);
    }
    return 0;
}
