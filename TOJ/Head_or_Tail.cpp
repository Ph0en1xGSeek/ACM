#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int ca, num, a, b;
    while(cin >> ca && ca != 0)
    {
        a = b = 0;
        for(int i = 0; i < ca; i++)
        {
            cin >> num;
            if(num == 1)
                a++;
            else
                b++;
        }
        printf("Mary won %d times and John won %d times\n", b, a);
    }
    return 0;
}
