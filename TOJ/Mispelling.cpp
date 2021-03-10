#include <iostream>
#include <string>

using namespace std;

int main()
{
    int ca;
    cin >> ca;
    string str;
    int num;
    for(int j = 1; j <= ca; j++)
    {
        cin >> num;
        cin >> str;
        cout << j << ' ';
        for(int i = 0; i < str.length(); i++)
            if(i != num-1)
                cout << str[i];
        cout << endl;
    }
    return 0;
}
