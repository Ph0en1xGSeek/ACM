#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string shuru;

    cin >> shuru;


    while(shuru[0] != '0')
    {
        num = 0;
        for(int i = 0; i < shuru.length(); i++)
            num += static_cast<int>(shuru[i] - '0') ;
        if(num % 9 != 0)
            cout << num % 9 << endl;
        else
            cout << 9 << endl;
        cin >> shuru;
    }
    return 0;
}
