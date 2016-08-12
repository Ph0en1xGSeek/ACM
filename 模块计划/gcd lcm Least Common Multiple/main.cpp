#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int ca;
    cin >> ca;
    int num, a, b;
    while(ca--)
    {
        cin >> num;
        cin >> a;
        for(int i = 0; i < num - 1; i++)
        {
            cin >> b;
            a = a/__gcd(a, b)*b;
        }
        cout << a << endl;
    }
    return 0;
}
