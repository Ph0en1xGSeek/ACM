#include <iostream>

using namespace std;

int main()
{
    int num;
    int x, y;
    cin >> num;
    for(int i = 0; i < num ; i++)
    {
        cin >> x >> y;
        if(x < y || (x + y) % 2 == 1 || (x - y) % 2 ==1)
        {
            cout << "impossible" << endl;
            continue;
        }
        cout << (x + y) / 2 << ' ' << (x - y) / 2 << endl;
    }
    return 0;
}
