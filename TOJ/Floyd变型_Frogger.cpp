#include <iostream>
#include <cmath>
#include <iomanip>

//求A到B所有路线中所需要跳跃力需求最小的那条路需要多少跳跃力

using namespace std;
struct point
{
  double x;
  double y;
}stone[201];

double dist(int i, int j)
{
    return sqrt((stone[i].x - stone[j].x)*(stone[i].x - stone[j].x)+(stone[i].y - stone[j].y)*(stone[i].y - stone[j].y));
}

double max(double a, double b)
{
    return a > b ? a : b;
}

double arr[201][201];

int main()
{
    int num , ca = 1;
    while(cin >> num && num)
    {
        for(int i = 0; i < num; i++)
            cin >> stone[i].x >> stone[i].y;
        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                arr[i][j] = arr[j][i] = dist(i, j);
        for(int k = 0; k < num; k++)
            for(int i = 0; i < num; i++)
                for(int j = 0; j < num; j++)
                    arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
        cout << "Scenario #" << ca++ << endl;
        cout << "Frog Distance = " << setprecision(3) << fixed << arr[0][1] << endl << endl;
    }

    return 0;
}
