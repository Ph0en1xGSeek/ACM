#include <iostream>

using namespace std;


int main()
{
    int speed[11];
    int time[11] = {0};
    int dist;
    int num;
    cin >> num;
    while(num != -1)
    {
        dist = 0;
        for(int i = 0; i < num; i++)
            cin >> speed[i + 1] >> time[i + 1];
        for(int i = 1; i <= num; i++)
            dist += speed[i] * (time[i] - time[i - 1]);
        cout << dist << " miles" << endl;
        cin >> num;
    }

   return 0;
}




