#include <iostream>

using namespace std;

int main()
{
    int num;
    int data;
    int counts;
    cin >> num;
    for(int i = 0; i < num ; i++)
    {
        counts = 0;
        cin >> data;
        while(data % 2 == 0)
        {
            data = data / 2;
            counts++;
        }
        cout << data << ' ' << counts << endl;
    }
    return 0;
}
