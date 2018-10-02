#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 15

using namespace std;

int main()
{
    bool flag;
    printf("变量个数\n");
    int n;
    scanf("%d", &n);
    printf("s.t个数\n");
    int m;
    scanf("%d", &m);
    double c[M];///目标函数系数
    double A[M][M];///系数矩阵
    double b[M];///限制值
    int XB[M];///基向量
    int ti, tj;
    double alpha[M];///检验因子
    double theta[M];
    double xi[M];///解
    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));
    memset(A, 0, sizeof(A));

    printf("输入%d目标函数系数\n", n);
    for(int i = 0; i < n; i++)
        scanf("%lf", &c[i]);
    printf("输入系数矩阵\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            A[i][n+j] = ((i==j)? 1.0:0.0);
    for(int i = 0; i < m; i++)
        XB[i] = i+n;
    printf("输入%d个限制值\n", m);
    for(int i = 0; i < m; i++)
        scanf("%lf", &b[i]);

    while(1)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n+m; j++)
                printf(" %lf", A[i][j]);
            puts("\n");
        }
        flag = false;
        double mx = -10;
        int mxPos = -1;///进基元素
        int minPos = 10000000;///枢纽元素
        for(int i = 0; i < n+m; i++)
        {
            alpha[i] = c[i];
            for(int j = 0; j < m; j++)
                alpha[i] -= c[XB[j]]*A[j][i];
            if(alpha[i] > 0)
            {
                if(alpha[i] > mx)
                {
                    mx = alpha[i];
                    mxPos = i;
                }
                flag = true;
            }
            printf(" %lf", alpha[i]);

        }
        printf("\n");
        double mi = 10000000;
        if(flag == true)///继续优化
        {
            for(int i = 0; i < m; i++)
            {
                theta[i] = b[i] / A[i][mxPos];
                if(theta[i] > 0)
                {
                    if(theta[i] < mi)
                    {
                        mi = theta[i];
                        minPos = i;
                    }
                }
            }
            printf("枢纽元素: %d, %d\n", minPos+1, mxPos+1);
            XB[minPos] = mxPos;
            ///A(minPos, mxPos)是枢纽元素
            for(int i = 0; i < n+m; i++)
                if(i != mxPos)
                    A[minPos][i] /= A[minPos][mxPos];
            b[minPos] /= A[minPos][mxPos];
            A[minPos][mxPos] = 1;
            for(int i = 0; i < m; i++)
            {
                if(i == minPos)
                    continue;
                for(int j = 0; j < n+m; j++)
                {
                    if(j != mxPos)
                        A[i][j] -= A[minPos][j] * (A[i][mxPos]);
                }
                b[i] -= b[minPos]*(A[i][mxPos]);
                A[i][mxPos] = 0;
            }
        }
        else///完成优化
        {
            memset(xi, 0, sizeof(xi));
            for(int i = 0; i < m; i++)
                xi[XB[i]] = b[i];
            printf("最优解: \n");
            for(int i = 1; i <= n+m; i++)
            {
                printf("X%d = %lf\n", i, xi[i-1]);
            }
            break;
        }
    }
    return 0;
}

/*
INTPUT:
2
3
7 12
9 4
4 5
3 10
360
200
300
*/


/*
OUTPUT:
变量个数
2
s.t个数
3
输入2目标函数系数
7 12
输入系数矩阵
9 4
4 5
3 10
输入3个限制值
360
200
300
 9.000000 4.000000 1.000000 0.000000 0.000000

 4.000000 5.000000 0.000000 1.000000 0.000000

 3.000000 10.000000 0.000000 0.000000 1.000000

 7.000000 12.000000 0.000000 0.000000 0.000000
枢纽元素: 3, 2
 7.800000 0.000000 1.000000 0.000000 -0.400000

 2.500000 0.000000 0.000000 1.000000 -0.500000

 0.300000 1.000000 0.000000 0.000000 0.100000

 3.400000 0.000000 0.000000 0.000000 -1.200000
枢纽元素: 2, 1
 0.000000 0.000000 1.000000 -3.120000 1.160000

 1.000000 0.000000 0.000000 0.400000 -0.200000

 0.000000 1.000000 0.000000 -0.120000 0.160000

 0.000000 0.000000 0.000000 -1.360000 -0.520000
最优解:
X1 = 20.000000
X2 = 24.000000
X3 = 84.000000
X4 = 0.000000
X5 = 0.000000
*/
