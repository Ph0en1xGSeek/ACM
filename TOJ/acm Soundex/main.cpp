#include <iostream>

using namespace std;
bool isIn(string a, char b)
{
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i]== b)
            return true;
    }
    return false;
}

int main()
{
    int arr[6] = {0};
    string coding;
    string past;
    string null;
    while(cin >> coding)
    {
        for(int i = 0; i < coding.length(); i++)
        {
            if(coding[i] == 'B' ||coding[i] == 'F' ||coding[i] == 'P' ||
               coding[i] == 'V')
               {
                   if(arr[0] == 0)
                   {
                        arr[0]++;
                        past += coding[i];
                   }
                   else
                   {
                       if(isIn(past, coding[i]))
                        arr[0]++;
                        else
                           past += coding[i];
                   }
               }

            else if(coding[i] == 'C' ||coding[i] == 'G' ||coding[i] == 'J' ||
               coding[i] == 'K' ||coding[i] == 'Q' ||coding[i] == 'S' ||coding[i] == 'X' ||
               coding[i] == 'Z')
                {
                   if(arr[1] == 0)
                   {
                        arr[1]++;
                        past += coding[i];
                   }
                   else
                   {
                       if(isIn(past, coding[i]))
                        arr[1]++;
                        else
                           past += coding[i];
                   }
               }
            else if(coding[i] == 'D' ||coding[i] == 'T')
                {
                   if(arr[2] == 0)
                   {
                        arr[2]++;
                        past += coding[i];
                   }
                   else
                   {
                       if(isIn(past, coding[i]))
                        arr[2]++;
                        else
                           past += coding[i];
                   }
               }
            else if(coding[i] == 'L')
                arr[3]++;
            else if(coding[i] == 'M' ||coding[i] == 'N')
                {
                   if(arr[4] == 0)
                   {
                        arr[4]++;
                        past += coding[i];
                   }
                   else
                   {
                       if(isIn(past, coding[i]))
                        arr[4]++;
                        else
                           past += coding[i];
                   }
               }
            else if(coding[i] == 'R')
                arr[5]++;
        }
        for(int i = 0; i < 6; i++)
        {
            if(arr[i] > 1)
                cout << i + 1 << i + 1;
            else if (arr[i] == 1)
                cout << i + 1;
        }
        cout << endl;
        for(int i = 0 ; i < 6 ; i++)
            arr[i] = 0;
        past = null;
    }
    return 0;
}
