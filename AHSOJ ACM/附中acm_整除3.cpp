#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int counts = 0;
    int total = 0 , target;
    cin >> target;
    for(int i = 1 ; i <= target ; i++)
    {
        total += i;
        if(total % 3 == 0)
            counts++;
    }
    cout << counts << endl;
    return 0;
}
