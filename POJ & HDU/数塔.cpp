#include <iostream>


using namespace std;
int dp[100][100];

int max(int a, int b)
{
    return a > b? a:b;
}

int main()
{
    int ca, num;
    cin >> ca;
    while(ca--)
    {
        cin >> num;
        for(int i = 0; i < num; i++)
            for(int j = 0; j <= i; j++)
                cin >> dp[i][j];
        for(int i = num-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
        cout << dp[0][0] << endl;
    }
    return 0;
}
