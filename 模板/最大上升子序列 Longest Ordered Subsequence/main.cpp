#include <iostream>

using namespace std;


int main()
{
    int arr[1001];
    int los[1001];//�Ե�i����Ϊ��β���������������
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
        if(los[i] > Max)//Ҫ����for����
                Max = los[i];
    }

    cout << Max << endl;
    return 0;
}
