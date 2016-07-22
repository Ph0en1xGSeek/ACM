#include <iostream>
#include <stdio.h>

using namespace std;

void hanoi(int n, char from, char mid, char to)
{
    if(n == 1)  printf("Move 1 from %c to %c\n", from, to);
    else
    {
        hanoi(n-1, from, to, mid);
        printf("Move %d from %c to %c\n", n, from, to);
        hanoi(n-1, mid, from, to);
    }
}

int main()
{
    hanoi(3, 'x', 'y', 'z');
    return 0;
}
