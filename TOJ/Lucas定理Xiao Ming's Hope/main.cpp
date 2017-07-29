#include <iostream>

using namespace std;

int main()
{
    int num, counts;
    while(cin >> num)
    {
        counts = 0;
        while(num)
        {
            if(num%2 == 1)
                counts++;
            num /= 2;
        }
        int ans = (1 << counts);
        cout << ans << endl;
    }
    return 0;
}
