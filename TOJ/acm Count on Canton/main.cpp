#include <iostream>

using namespace std;
int whichLine(int num);


int main()
{
    int num;
    int n1 , n2;
    while(cin >> num)
    {
        int line = whichLine(num);
        int ran = num - (line * (line - 1)) / 2 - 1;

        if (line % 2 == 0)
        {
            n1 = 1 + ran;
            n2 = line - ran;
        }
        else
        {
            n1 = line - ran;
            n2 = 1 + ran;
        }


        cout << "TERM " << num << " IS " << n1 << "/" << n2 << endl;

    }
    return 0;
}


int whichLine(int num)
{
    for(int n = 0 ; ; n++)
    {
        if ((n * (n + 1)) / 2 >= num && (n * (n - 1)) / 2 < num)
            return n;
    }
}
