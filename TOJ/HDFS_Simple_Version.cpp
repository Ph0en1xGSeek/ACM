#include <stdio.h>

using namespace std;

int main()
{
    int num;
    int m;
    int n;
    int a[2];
    bool isp = false;
    char arr2[3]={'p', 'q', 'r' };
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        isp = false;
        scanf("%d", &m);
        char** arr = new char*[m];
        for(int j = 0; j < m; j++)
            arr[j] = arr2;
        for(int j = 0; j < 2*(m - 1); j++)
        {
            scanf("%d", &n);
            arr[n-1]++;
        }
        for(int j = 0; j < m; j++)
        {
            if(*arr[j] == 'q')
            {
                if(isp)
                {
                    a[1] = j;

                }

                else
                {
                    a[0] = j;
                    isp = true;
                }

            }
            else if(*arr[j] == 'p')
            {
                a[0] = j;
                a[1] = j;
            }

        }
        printf("%d %d\n", a[0]+1, a[1]+1);
        delete [] arr;
    }
    return 0;
}
