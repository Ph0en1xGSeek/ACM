#include <iostream>

using namespace std;

int main()
{
    int num;
    int a, b, c;
    cin  >> num;
    while(num--)
    {
        cin >> a >> b >> c;
        if(b - a > c)
            cout << "advertise" << endl;
        else if(b-a==c)
            cout << "does not matter" << endl;
        else
            cout << "do not advertise" << endl;
    }
    return 0;
}
