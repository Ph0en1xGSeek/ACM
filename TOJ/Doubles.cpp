#include <iostream>

using namespace std;
int arr[16];

int main()
{
    while(1)
    {
        int counts = 0;
        for(int i = 0; i < 16; i++)
        {
            cin >> arr[i];
            if(arr[i] == 0)
                break;
            else if(arr[i] == -1)
                return 0;
            for(int j = 0; j < i; j++)
            {
                if(arr[j] == 2 * arr[i] || arr[i] == arr[j] * 2)
                    counts++;
            }
        }
        cout << counts << endl;
    }
    return 0;
}
