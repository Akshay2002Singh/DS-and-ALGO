#include<stdio.h>

void hanoi(int n,char from,char to ,char aux)
{
    if (n==1)
    {printf("move disk %d from %c to %c \n",n,from,to);
    return;
    }
    hanoi(n-1,from,aux,to);
    printf("move disk %d from %c to %c \n",n,from,to,aux);
    hanoi(n-1,aux,to,from);
}
int main()
{
    hanoi(4,'A','B','C');

    return 0;
}