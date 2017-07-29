#include<iostream>
#include<string>
#include<vector>
#include <stdio.h>
using namespace std;

int N;
vector<double> X;
vector<double> Y;
double Lagrange(double x)
{
    double result = 0;
    for(int i = 0; i < N; i++)
    {
        double temp = Y[i];
        for(int j = 0; j < N; j++)
        {
            if(i != j)
            {
                temp = temp * (x - X[j]);
                temp = temp / (X[i] - X[j]);
            }
        }
        result += temp;
    }
    return result;
}

int main()
{
      while(1)
      {
            printf("n: ");
            scanf("%d", &N);
            printf("(xi, yi): ");
            X.clear();
            Y.clear();
            double tmp1, tmp2;
            for(int i = 0; i < N; i++)
            {
                scanf("%lf %lf", &tmp1, &tmp2);
                X.push_back(tmp1);
                Y.push_back(tmp2);
            }
            printf("X: ");
            double x;
            scanf("%lf", &x);
            double result = Lagrange(x);
            printf("result: %lf\n", result);
      }
      return 0;
}


