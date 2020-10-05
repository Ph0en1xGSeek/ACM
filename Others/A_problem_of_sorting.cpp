#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    string color;
    string n;
    bool operator<(const node& b) const
    {
        if(n.compare(b.n) == 1)
            return true;
        return false;
    }
}arr[150];

int main()
{
    int ca;
    int num;

    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        getchar();
        for(int i = 0; i < num; i++)
        {
            string str;
            getline(cin, str);
            arr[i].color = str.substr(0, str.length()-5);
            arr[i].n = str.substr(str.length()-4);
        }
        sort(arr, arr+num);
        for(int i = 0; i < num; i++)
        {
            cout << arr[i].color << endl;
        }
    }
    return 0;
}
