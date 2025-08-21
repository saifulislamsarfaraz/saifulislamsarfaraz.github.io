#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int sum;
    scanf("%d",&sum);
    int p,q,m=0,x=0,cnt=0;
    for(p=n-1; p>=0; p--)
    {
        cnt=0,x=0;
        for(q=p; q>=0; q--)
        {
            x=x+a[q];
            if(sum>=x)
            {
                cnt++;
                if(m<cnt)
                {
                    m=cnt;
                }
            }
            else
            {
                x=0;
                cnt=0;
                break;
            }
        }
    }
    printf("%d\n",m);
}
