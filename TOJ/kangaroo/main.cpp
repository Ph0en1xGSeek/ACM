#include <iostream>

using namespace std;

int main()
{
    int left, mid, right, tmp;
    while(cin >> left >> mid >> right)
    {
        cout << max(mid-left, right-mid)-1 << endl;
    }
    return 0;
}
