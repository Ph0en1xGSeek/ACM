#include <iostream>

using namespace std;

int main()
{

    int n;
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> n;
        int square = n * n;
        int range = (n / 2) * 2;
        if(n % 2 == 1)
            cout << square - range << ' ' << square + range << endl;
        else
            cout << square - range + 1 << ' ' << square + range - 1 << endl;
    }
    return 0;
}
