#include<bits/stdc++.h>
using namespace std;
int prime[100100];
int primcnt;
int marked[100105];
void sieve(int n)
{
    marked[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(marked[i]==0)
        {
            prime[primcnt]=i;
            primcnt++;
            for(int j=2*i; j<=n; j+=i)
            {
                marked[j]=1;
            }
        }
    }
    for(int i=0; i<primcnt; i++)
    {
        printf("%d\n",prime[i]);
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    sieve(n);
    return 0;
}


