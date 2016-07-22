#include <iostream>

using namespace std;

int main()
{
    bool isLose = false;
    int x, y, num;
    cin >> x >> y >> num;
    bool** arr = new bool* [x+2];
    for(int i = 0 ; i < x+2; i++)
    {
        arr[i] = new bool [y+2];
        for(int j = 0; j < y+2; j++)
            arr[i][j] = 0;
    }
    int a,b,step = 0;
    for(int i = 0 ; i < num; i++)
    {
        cin >> a >> b;
        if(isLose)
            continue;
        else
        {
            arr[a][b] = true;
            if(arr[a-1][b]&&arr[a][b-1]&&arr[a-1][b-1])
            {
                isLose = true;
                step = i+1;
            }
            if(arr[a+1][b]&&arr[a][b-1]&&arr[a+1][b-1])
            {
                isLose = true;
                step = i+1;
            }
            if(arr[a+1][b]&&arr[a][b+1]&&arr[a+1][b+1])
            {
                isLose = true;
                step = i+1;
            }
            if(arr[a-1][b]&&arr[a][b+1]&&arr[a-1][b+1])
            {
                isLose = true;
                step = i+1;
            }
        }

    }
    cout << step << endl;




    return 0;
}
