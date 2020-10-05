#include <iostream>

using namespace std;

int main()
{
    bool is ;
    int num;
    int arr[3000];
    while(cin >> num)
    {

        for(int i = 0 ; i < num; i++)
            cin >> arr[i];
        if(num == 1)
        {
            cout << "Jolly" << endl;
            continue;
        }
        for(int i = 1; i < num ; i++)
        {
            is = false;
            int a = (arr[i] - arr[i-1] > 0)?  arr[i] - arr[i-1]:arr[i - 1] - arr[i];
            for(int j =0; j < num ; j++)
            {
                if(arr[j] == a)
                {
                    is = true;
                    break;
                }
            }
            if(!is)
                break;
        }
        if(!is)
            cout << "Not jolly" << endl;
        else
            cout << "Jolly" << endl;
    }
    return 0;
}
