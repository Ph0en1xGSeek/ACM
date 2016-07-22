#include <iostream>

using namespace std;
int arr[100][100];
int main()
{
    int sum;
    int num;
    int counts1,counts2;
    int row;
    int col;
    cin >> num;
    while(num)
    {
        for(int i = 0; i < num; i++)
        {
            for(int j = 0; j < num; j++)
                cin >> arr[i][j];
        }
        counts1 = 0;
        for(int i = 0; i < num; i++)
        {
            sum = 0;
            for(int j = 0; j < num; j++)
                sum += arr[i][j];
            if(sum % 2 == 1)
            {
                row = i;
                counts1++;
                if(counts1 == 2)
                    break;
            }
        }
        counts2 = 0;
        for(int i = 0; i < num; i++)
        {
            sum = 0;
            for(int j = 0; j < num; j++)
                sum += arr[j][i];
            if(sum % 2 == 1)
            {
                col = i;
                counts2++;
                if(counts2 == 2)
                    break;
            }
        }
        if(counts1 == 0 && counts2 == 0)
            cout << "OK" << endl;
        else if(counts1 > 1 || counts2 > 1)
            cout << "Corrupt" << endl;
        else if((counts1 != 0 && counts2 == 0) ||(counts2 != 0 && counts1 == 0))
            cout << "Corrupt" << endl;
        else
            cout << "Change bit (" << row + 1<< ',' << col + 1 << ')' << endl;

        cin >> num;
    }

    return 0;
}
