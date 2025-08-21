#include <bits/stdc++.h>
using namespace std;
int ara[1000100];
long long version;
void merge_sort(int ara[], int n)
{
    if(n==1)
    {
        return;
    }
    int mid=n/2-1;
    int leftSize=mid+1;
    int rightSize=n-leftSize;
    int left[leftSize+1];
    int right[rightSize+1];
    for(int i=0; i<=mid; i++)
    {
        left[i]=ara[i];
    }
    for(int i=mid+1; i<n; i++)
    {
        right[i-mid-1]=ara[i];
    }
    merge_sort(left, leftSize);
    merge_sort(right, rightSize);
    int mk1=0, mk2=0, cnt=0;
    while(mk1<leftSize && mk2<rightSize)
    {
        if(left[mk1]<=right[mk2])
        {
            ara[cnt]=left[mk1];
            cnt++;
            mk1++;
        }
        else
        {
            ara[cnt]=right[mk2];
            cnt++;
            mk2++;
            version+=leftSize-mk1;
        }

    }
    while(mk1<leftSize)
    {
        ara[cnt]=left[mk1];
        mk1++;
        cnt++;
    }
    while(mk2<rightSize)
    {
        ara[cnt]=right[mk2];
        mk2++;
        cnt++;
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &ara[i]);
    }
    merge_sort(ara, n);
    printf("%lld",version);
    return 0;
}
