#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
int A[22] = {0, 1, 2, 6};
int b[22] = {0, 0, 1, 2};

int main()
{
    for(int i = 4; i < 23; i++)
    {
        A[i] = i * A[i-1];
        b[i] = (i-1)*(b[i-1]+b[i-2]);
    }
    int ca, n;
    cin >> ca;
    while(ca--)
    {
        cin>>n;
        cout << setprecision(2)<<fixed<<((b[n]*1.0)/A[n])*100<<"%"<<endl;
    }
    return 0;
}
