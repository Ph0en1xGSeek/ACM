#include <stdio.h>
struct Node
{
    double x, y;
}node[100];
int main()
{
    double chang, kuan, men, num, mianji, zongmianji;
    scanf("%lf%lf%lf%lf", &chang, &kuan, &men, &num);
    while(chang != 0)
    {
        zongmianji = chang * kuan;
        mianji = zongmianji / num;
        double ss = 0.0;
        for(int i = 0; i < num - 1; i++)
        {
            ss += mianji;
            if(ss <= (chang - men) * kuan /2)
            {
                node[i].x = chang;
                node[i].y = 2 * ss / (chang - men);
            }
            else if(ss <= (2 * chang - men) * kuan / 2)
            {
                node[i].y = kuan;
                node[i].x = 2 * chang - men - 2 * ss / kuan;
            }
            else
            {
                node[i].x = 0;
                node[i].y = 2 * (zongmianji - ss) / men;
            }
        }
        for(int i = 0; i < num - 1; i++)
        {
            if(i >= 1)
                printf(" ");
            printf("%.3f %.3f", node[i].x, node[i].y);
        }
        printf("\n");
        scanf("%lf%lf%lf%lf", &chang, &kuan, &men, &num);
    }
    return 0;
}
