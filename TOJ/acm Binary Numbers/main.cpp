#include <iostream>
#include <string>

using namespace std;

int main()
{
     string goal;
     int deci;
     cin >> deci;

    while(deci != 0)
    {
        int wei = deci % 2;
        deci = deci / 2;

            goal += '0' + wei;

    }
    for(int a = 0 ; a < goal.length() ; a++)
    {
        if(goal[a] == '1')
            cout << a << ' ';
    }
    return 0;
}
