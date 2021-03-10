#include <iostream>


using namespace std;

int pow(int num, int mi)
{
    int n = 1;
    for(int i = 0; i < mi; i++)
        n = n * num;
    return n;
}

int main()
{
    int n;
    cin >> n;
    while(n)
    {
        if(n % 3 == 0)
            cout << pow(n * n * n, n / 3) << endl;
        else if(n % 3 == 1)
            cout << n * pow(n * n * n, n / 3) << endl;
        else
            cout << n * n * pow(n * n * n, n / 3) << endl;
        cin >> n;
    }
    return 0;
}
