#include <bits/stdc++.h>
using namespace std;

int ara[10000];
int n;

void selection_sort()
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ara[i]>ara[j])
            {
                swap(ara[j], ara[i]);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &ara[i]);
    }
    selection_sort();
    for(int i=0; i<n; i++)
    {
        printf("%d ", ara[i]);
    }
    return 0;
}
