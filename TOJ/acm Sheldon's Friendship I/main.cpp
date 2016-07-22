#include <iostream>
#include <string>


using namespace std;


int main()
{
    string name[4];
    int value[4];
    int minimum = 100;
    int m = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        cin >> name[i];
        cin >> value[i];
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        if(value[i] < minimum)
        {
            minimum = value[i];
            m = i;
        }

    }

    cout << "\nPoor " << name[m] << endl;
    return 0;
}

