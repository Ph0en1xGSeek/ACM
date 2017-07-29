#include <iostream>
#include <string>

using namespace std;

int ch[7]= {0, 1, 2, 5, 6, 8, 9};
char dui[10] = {'0', '1', '2', '*', '*', '5', '9', '*', '8', '6'};

int main()
{
    int k, num;
    string str, emp;
    while(cin >> k)
    {
        str = emp;
        while(k)
        {
            num = k % 7;
            str += dui[ch[num]];
            k /= 7;
        }
        cout << str << endl;
    }
    return 0;
}
