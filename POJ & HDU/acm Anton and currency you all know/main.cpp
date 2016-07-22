#include <iostream>
#include <string>

using namespace std;

int main()
{
    string num;
    bool haveEven, isSwap;
    while(cin >> num)
    {
        haveEven = false;
        isSwap = false;
        int point = 0;
        for(int i = 0; i < num.length() - 1; i++)
        {
            if(num[i] % 2 == 0)
            {
                haveEven = true;
                point = i;
                if(num[i] < num[num.length() - 1] )
                {
                    isSwap = true;
                    char temp = num[i];
                    num[i] = num[num.length() - 1];
                    num[num.length() - 1]= temp;
                    break;
                }
            }

        }
        if(haveEven)
        {
            if(isSwap)
                cout << num << endl;
            else
            {
                char temp = num[point];
                num[point] = num[num.length() - 1];
                num[num.length() - 1]= temp;
                cout << num << endl;
            }

        }
        else
            cout << -1 << endl;
    }
    return 0;
}
