#include <iostream>
#include <string>

using namespace std;

int main()
{
    int line;
    cin >> line;
    for(int j = 0 ; j < line ; j++)
    {
        string num;
        cin >> num;
        int len = num.length();
        int* pNum = new int [len];
        int total = 0;
        for(int i = 0 ; i < len ; i++)
        {
            pNum[i] = num[i] - '0';
        }

        for(int i = 0 ; i < len ; i++)
        {
            total += pNum[i];
        }
        cout << total << endl;

    }


    return 0;
}
