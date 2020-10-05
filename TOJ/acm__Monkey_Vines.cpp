#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int line;
    string vines;
    int deep , deepest;
    cin >> line;
    cin.get();
    int* solu = new int[line];
    for(int i = 0 ; i < line ; i++)
    {
        deep = 0;
        deepest = 0;
        getline(cin , vines);
        for (int j = 0 ; j < vines.length() ; j++)
        {
            if(vines[j] == '[')
                deep++;
            if(vines[j] == ']')
                deep--;

            if(deep > deepest)
                deepest = deep;
        }
        solu[i] = pow(2 , deepest);
    }

    for(int i = 0 ; i < line ; i++)
    {
        cout << i + 1 << " " << solu[i] <<endl;
    }
    return 0;
}
