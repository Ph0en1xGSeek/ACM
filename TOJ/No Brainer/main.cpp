#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string a, b;
    cin >> num;
    while(num--)
    {
        cin >> a >> b;
        if(a.length() > b.length())
            cout << "MMM BRAINS" << endl;
        else if(a.length() < b.length())
            cout << "NO BRAINS" << endl;
        else
        {
            for(int i = 0; i < a.length(); i++)
            {
                if(a[i] < b[i])
                {
                    cout << "NO BRAINS" << endl;
                    goto end;
                }
            }
            cout << "MMM BRAINS" << endl;
            end:;
        }
    }
    return 0;
}
