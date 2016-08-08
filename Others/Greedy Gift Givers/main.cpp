#include <iostream>
#include <string>
using namespace std;

bool isEqual(string s1, string s2)
{
    if(s1.length() != s2.length())
        return false;
    else
    {
        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] != s2[i])
                return false;
        }
        return true;
    }
}


int main()
{
    int num;
    string n;
    int point;
    int money, giveTo;
    cin >> num;
    string name[10];
    int arr[10] = {0};
    for(int i = 0; i < num; i++)
    {
        cin >> name[i];
    }
    for(int i = 0; i < num; i++)
    {
        cin >> n;
        for(int j = 0; j < num ;j++)
        {
            if(isEqual(n , name[j]))
            {
                point = j;
                break;
            }
        }
        cin >> money >> giveTo;
        arr[point] -= money;
        arr[point] += (giveTo == 0)? money : money % giveTo;
        for(int m = 0; m < giveTo; m++)
        {
            cin >> n;
            for(int j = 0; j < num; j++)
            {
                if(isEqual(n , name[j]))
                {
                    point = j;
                    break;
                }
            }
            arr[point] += money / giveTo;
        }


    }
    for(int i = 0; i < num; i++)
    {
        cout << name[i] << ' ' << arr[i] << endl;
    }
    return 0;
}
