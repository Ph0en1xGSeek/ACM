#include <iostream>
#include <cstring>

using namespace std;
int arr[32769];

int main()
{
    int ca, num, counts;
    cin >> ca;
    while(ca--)
    {
        counts = 0;
        cin >> num;
        memset(arr, 0, sizeof(arr));
        for(int i = 2; i < num; i++)
        {
            if(arr[i] == 0 && num % i == 0)
            {
                for(int j = i; j < num; j += i)//去掉所有以i为公因数的数
                    arr[j] = 1;
            }
        }
        for(int i = 1; i < num; i++)
            if(arr[i] == 0)
                counts++;
        cout << counts << endl;
    }
    return 0;
}
