#include <iostream>

using namespace std;

int main()
{
    int mi, mx;
    int ans = 0;
    int num;
    int tmp;
    cin >> num;
    cin >> tmp;
    mi = mx = tmp;
    for(int i = 1; i < num; i++)
    {

        cin >> tmp;
        if(tmp < mi)
        {
            ans++;
            mi = tmp;
        }
        if(tmp > mx)
        {
            ans++;
            mx = tmp;
        }

    }
    cout << ans << endl;
    return 0;
}
