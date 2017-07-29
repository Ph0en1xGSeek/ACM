#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[101];
    int ca;
    while(cin >> ca)
    {
        for(int i = 0; i < ca; i++)
            cin >> arr[i];
        sort(arr, arr+ca);
        cout << arr[0];
        for(int i = 1; i < ca; i++)
            cout << ' ' << arr[i];
        cout << endl;
    }
    return 0;
}
