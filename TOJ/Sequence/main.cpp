#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int arr[5];
int baseArr[5];
int num;

bool change(int base)
{
    int tmp, counts, bit, ans;
    for(int i = 0; i < num; i++)
    {
        ans = counts = 0;
        tmp = arr[i];
        while(tmp)
        {
            bit = tmp % 10;
            if(bit >= base)
                return false;
            ans += bit * pow(base, counts);
            counts++;
            tmp /= 10;
        }
        baseArr[i] = ans;
    }
    tmp = baseArr[1] - baseArr[0];
    for(int i = 2; i < num; i++)
        if(baseArr[i] - baseArr[i-1] != tmp)
            return false;
    return true;

}

int main()
{
    int t;
    while(cin >> num, num)
    {
        t = 0;
        for(int i = 0; i < num; i++)
            cin >> arr[i];
        for(int i = 2; i <= 10; i++)
        {
            if(change(i))
            {
                t = 1;
                cout << "Minimum base = " << i << '.' << endl;
                break;
            }
        }
        if(t == 0)
            cout << "No base <= 10 can be found." << endl;
    }
    return 0;
}
