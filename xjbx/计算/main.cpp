#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int n1 = 2 , n2 = 1 , total = 0;
    int temp;
    total += (n1 / n2);
    for (int i = 1 ; i <=55 ; i++)
    {
        temp = n1;
        n1 += i;
        n2 = n1;
        total += (n1 / n2);
    }
    cout << total;


    return 0;
}
