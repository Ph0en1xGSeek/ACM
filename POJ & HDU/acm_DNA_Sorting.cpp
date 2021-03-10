#include <stdio.h>
#include <algorithm>

using namespace std;

struct DNA
{
    int nixu;
    char xulie [110];
};

int nixushu(char* xulie, int len)
{
    int nixu = 0;
    int a = 0 ,c = 0, g = 0;//numberOf
    for(int i = len - 1; i >= 0; i--)
    {
        switch(xulie[i])
        {
            case 'A':
                a++;
                break;
            case 'C':
                c++;
                nixu += a;
                break;
            case 'G':
                g++;
                nixu += a;
                nixu += c;
                break;
            case 'T':
                nixu += a;
                nixu += c;
                nixu += g;
                break;
        }
    }
    return nixu;
}

int cmp(const void* a,const void* b)
{
    return (*(DNA*)a).nixu - (*(DNA*)b).nixu;
}

int main()
{
    int len;
    int num;
    scanf("%d%d", &len, &num);

    DNA* arr = new DNA [num];
    for(int i = 0; i < num; i++)
    {
        scanf("%s", arr[i].xulie);
        arr[i].nixu = nixushu(arr[i].xulie, len);
    }
    qsort(arr, num, sizeof(arr[0]), cmp);
    for(int i = 0; i < num; i++)
        printf("%s\n", arr[i].xulie);
    delete [] arr;



    return 0;
}
