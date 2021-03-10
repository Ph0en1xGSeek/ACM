#include <iostream>
#include <string>

using namespace std;

int main()
{
    char wei;
    int l;

    cin >> l;
    string b;
    string station = "             ";
    for(int i = 0 ; i < l ; i++)
    {
        cin >> wei;
        b += wei;
    }
    int len = b.length();//要找的数


    int mx = len;//找的位置+1
    int stationCoal = 0;

    while(mx > 0)
    {
        if(stationCoal != 0 && station[stationCoal] == static_cast<int>(len + '0'))
        {
            len--;
            //station[stationCoal] == '';
            stationCoal--;
        }

        else if(b[mx - 1] == static_cast<int>(len + '0'))
        {
            len--;
            mx--;
        }
        else
        {
            station[stationCoal + 1] = b[mx - 1];
            stationCoal++;
            mx--;
        }
    }

    if(station == "")
    {
        cout << "Yes" << endl;
        return 0;
    }

    for(int i = stationCoal ; i >= 1 ; i--)
    {
        if(station[i] == static_cast<int>(len + '0'))
        {
            len--;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }

    }
    cout << "Yes" << endl;



    return 0;
}
