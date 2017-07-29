#include <iostream>

using namespace std;
bool isInSort(int seq[] , int numberOfElement);

int main()
{
    cout << "Input number and sequence: " << endl;
    int line;
    int counts = 0;
    int solu[10] = {0};
    cin >> line;
    for(int a = 0 ; a < line ; a++)
    {

        int numberOfElement;
        int counts = 0;

        cin >> numberOfElement;
        int seq[15] = {0};
        for(int i = 0 ; i < numberOfElement ; i++)
            cin >> seq[i];

        while(!isInSort(seq , numberOfElement))//Bubble sort and count the time swap
        {
            for(int i = 0 ; i < numberOfElement - 1 ; i++)
            {
                if(seq[i] > seq[i + 1])
                {
                    swap(seq[i] , seq[i + 1]);
                    counts++;
                }

            }
        }
        solu[a] = counts;
    }
    for(int i = 0 ; i < line ; i++)
        cout << "Scenario #" << i + 1 << ":" << endl << solu[i] << endl << endl;


    return 0;
}


bool isInSort(int seq[] , int numberOfElement)
{
    for(int i = 0 ; i < numberOfElement - 1 ; i++)
    {
        if (seq[i] > seq[i + 1])
            return false;
    }
    return true;

}
