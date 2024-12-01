#include <bits/stdc++.h>
using namespace std;
int n;
int d;
int ara[100000];
int q[100000];

int binary_search(int x)
{
    int low=0;
    int high=n-1;
    int mid;
    while(high>=low)
    {
        mid=(high+low)>>1;
        if(ara[mid]>x)
            high=mid-1;
        else if(ara[mid]<x)
            low=mid+1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&d);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &ara[i]);
    }
    for(int i=0; i<d; i++)
    {
        scanf("%d",&q[i]);
    }
    for(int i=0; i<d; i++)
    {
        cout<<binary_search(q[i])<<endl;
    }

    return 0;
}

