#include <iostream>

using namespace std;

int main()
{
    int ca;
    long long num;
    cin >> ca;
    while(ca--)
    {
        cin >> num;
        if (num == 2)
            cout << 1 << endl;
        else if(num & 1)
            cout << num/2 * (num/2+1) << endl;
        else
        {
            if(num/2 & 1)
                cout << (num/2-2) * (num/2+2) << endl;
            else
                cout << (num/2-1) * (num/2+1) << endl;
        }
    }
    return 0;
}
