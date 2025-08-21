#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int f_nth_element(int n, int a, int b, int c)
{
    if(n==1)
        return a;
    else if(n==2)
        return b;
    else if(n==3)
        return c;
    else
        return (n-1)+(n-2)+(n-3);
}

int main()
{
    int n,a,b,c,e;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    e= f_nth_element(n,a,b,c);
    printf("%d",e);
    return 0;
}
