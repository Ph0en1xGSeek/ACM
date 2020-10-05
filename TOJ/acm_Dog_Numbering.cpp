#include <iostream>

using namespace std;
void bubleSort(int arr[] , int range);

int main()
{
    cout << "Dog!" << endl;

    int maxNum[50];
    int numOfDog , result = 1;
    cin >> numOfDog;
    for(int i = 0 ; i < numOfDog ; i++)
        cin >> maxNum[i];

    bubleSort(maxNum , numOfDog);
    for(int i = 0 ; i < numOfDog ; ++i)
    {
        result *= (maxNum[i] - i);
        if(result == 0)
            break;
    }
    cout << result << endl;

    return 0;
}

void bubleSort(int arr[] , int range)
{
    for (int j = 1; j < range - 1; ++j)
    {
        for (int i = 0; i < range - j; ++i)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i] , arr[i + 1]);
        }
    }

}
