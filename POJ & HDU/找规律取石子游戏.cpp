#include <iostream>

using namespace std;
int fbnq[50] = {1, 1, 2, 3};

/**�ҹ��ɻᷢ��쳲�������Ϊ�ذ�̬**/

int main()
{
    int i;
    for(i = 4; i <= 45; i++)
        fbnq[i] = fbnq[i-1] + fbnq[i-2];
    int n;
    while(cin >> n , n)
    {
        for(i = 0; i <= 45; i++)
            if(n == fbnq[i])
                break;
        if(i != 46)
            cout << "Second win\n";
        else
            cout << "First win\n";
    }
    return 0;
}
