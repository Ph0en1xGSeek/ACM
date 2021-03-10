#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world! I'm a happy ant" << endl;

    int len;
    int num;
    int longest , shortest = 0;

    cin >> len;
    cin >> num;
    int* position = new int[num];
    int high = 0;
    int low = num;
    for(int i = 0 ; i < num ; i++)
        cin >> position[i];

    for(int i = 0 ; i < num ; i++)
    {
        if(position[i] > high)
            high = position[i];
        if(position[i] < low)
            low = position[i];
    }

    for(int i = 0 ; i < num ; i++)
    {
        if(min(position[i] , len - position[i]) > shortest)
            shortest = min(position[i] , len - position[i]);
    }

    longest = max(len - low , high);


    cout << shortest << ' ' << longest << endl;


    return 0;
}
