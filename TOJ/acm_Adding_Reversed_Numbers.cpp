#include <stdio.h>
using namespace std;

int reverse(int num)
{
    int rev = 0;
    int remain;
    while(num)
    {
        rev *= 10;
        remain = num % 10;
        rev += remain;
        num /= 10;
    }
    return rev;

}

int main()
{
    int num;
    int a, b;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d%d", &a, &b);
        int temp = reverse(a) + reverse(b);
        printf("%d\n" , reverse(temp));
    }
    return 0;
}
