#include<bits/stdc++.h>
using namespace std;
int marked{100100};
int nod[100100];
int sod[100100];
void sieve(int n)
{
    for(int i=1; i<=n; i++)
    {
        nod[i]=0;
        sod[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            nod[j]++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            sod[j]+=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
         printf("%d %d\n",nod[i],sod[i]);
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    sieve(n);
    return 0;
}


