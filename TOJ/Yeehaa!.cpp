#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.141592653589793
using namespace std;

int main()
{
    int ca;
    cin >> ca;
    double R, r;
    int n;
    for (int i = 1; i <= ca; i++)
    {
        cin >> R >> n;
        r = R * (sin(pi/n)/(sin(pi/n)+1));
        cout << "Scenario #" << i << ":" << endl;
        cout << setprecision(3) << fixed << r << endl << endl;
    }
    return 0;
}
