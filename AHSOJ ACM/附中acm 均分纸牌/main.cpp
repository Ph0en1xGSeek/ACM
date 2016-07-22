#include <iostream>

using namespace std;
int average(int arr[] , int SIZE);

int main()
{
    int counts = 0;
    int numOfPile;
    cin >> numOfPile;
    int* card = new int [numOfPile];
    for(int i = 0 ; i < numOfPile ; i++)
        cin >> card[i];
    for(int i = 0 ; i < numOfPile - 1 ; i++)
    {
        int avg = average( card , numOfPile) ;
        if(card[i] != avg)
        {
            card[i + 1] -= (avg - card[i]);
            counts++;
            card[i] = avg;
        }
    }

    cout << counts <<endl;

    return 0;
}

int average(int arr[] , int SIZE)
{
    int total = 0;
    for(int i = 0 ; i < SIZE ; i++)
    {
        total += arr[i];
    }
    return total / SIZE;
}
