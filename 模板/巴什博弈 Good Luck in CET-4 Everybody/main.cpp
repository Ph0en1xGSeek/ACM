#include <iostream>

using namespace std;
int sg[1005] = {0};//1±ØÊ¤

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 1; i < 1005; i++)
            for(int j = 0; (1 << j) <= i; j++)
            {
                if(sg[i-(1<<j)] == 0)
                {
                    sg[i] = 1;
                    break;
                }
            }
        if(sg[n] == 1)
            cout << "Kiki" << endl;
        else
            cout << "Cici" << endl;
    }
    return 0;
}
