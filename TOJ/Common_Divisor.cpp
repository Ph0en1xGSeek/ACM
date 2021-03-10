#include <iostream>
#include <cstring>

using namespace std;
int arr[1008];

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int num;
    int a, b, k, ans;
    int ca;
    cin >> ca;
    while(ca--)
    {
        k = 0;
        ans = 1;
        int tmp;
        cin >> a >> b;
        num = gcd(a, b);
        for(int i = 2; i < num;)
        {
            tmp = 1;
            while(!(num % i))
            {
                num /= i;
                tmp++;
            }
            if(tmp != 1)
            {
                arr[k] = tmp;
                k++;
            }
            if(i & 1)
                i+=2;
            else
                i++;
        }
        if(num != 1)
        {
            arr[k] = 2;
            k++;
        }
        for(int i = 0; i < k; i++)
            ans *= arr[i];
        cout << ans << endl;
    }
    return 0;
}
