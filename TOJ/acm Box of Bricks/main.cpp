#include <iostream>

using namespace std;

int main()
{
    int set = 0;
    int arr[50];
    int num;
    cin >> num;
    while(num != 0)
    {
        set++;
        int counts = 0;
        int total = 0;
        for(int i = 0; i < num; i++)
            cin >> arr[i];
        for(int i = 0; i < num; i++)
            total += arr[i];
        total = total / num;
        for(int i = 0; i < num; i++)
        {
            if(arr[i] > total)
                    counts += (arr[i] - total);
        }
        cout << "Set #" << set << endl;
        cout << "The minimum number of moves is " <<  counts << "." << endl << endl;
        cin >> num;
    }
    return 0;
}
