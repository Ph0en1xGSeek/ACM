#include <iostream>

using namespace std;


int main()
{
    int arr[1001];
    int los[1001];//以第i个数为结尾的最大上升子序列
    int num, Max;

    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    Max = 0;
    for(int i = 0; i < num; i++)
    {
        los[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && los[i] < los[j] + 1)
                los[i] = los[j] + 1;

        }
        if(los[i] > Max)//要放在for外面
                Max = los[i];
    }

    cout << Max << endl;
    return 0;
}
