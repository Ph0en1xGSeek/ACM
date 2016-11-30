#include<iostream>
#include<string>
#include<vector>
#include <stdio.h>

using namespace std;

vector<double> X;
vector<double> Y;
int n;

double ChaShang(int N)
{
    double f = 0;
    double temp = 0;
    for(int i = 0; i < N+1; i++)
    {
        temp = Y[i];
        for(int j = 0; j < N+1; j++)
            if(i!=j)
                temp /= (X[i]-X[j]);
        f += temp;
    }
    return f;
}

double Newton(double x)
{
    double result = 0;
    for(int i = 0; i < X.size(); i++)
    {
        double temp = 1;
        double f = ChaShang(i);
        for(int j = 0; j < i; j++)
        {
            temp = temp*(x - X[j]);
        }
        result += f*temp;
    }
    return result;
}


int main()
{
    while(1)
    {
        printf("n: ");
        scanf("%d", &n);
        X.clear();
        Y.clear();
        double tmp1, tmp2;
        printf("(Xi, Yi): \n");
        for(int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &tmp1, &tmp2);
            X.push_back(tmp1);
            Y.push_back(tmp2);
        }
        double x;
        printf("x: ");
        scanf("%lf", &x);
        double result = Newton(x);
        printf("Result: %lf\n", result);
    }
}
