#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int num;
    cin >> num;

    while(num != 0)
    {
        int counts = 0;
        while(num != 1)
        {
            if(num % 2 == 0)
                num = num / 2;
            //if(num % 2 == 1)

            else
                num = 3 * num + 1;
            counts++;
        }
        cout << counts + 1 << endl;
        cin >> num;
    }
    return 0;
}
