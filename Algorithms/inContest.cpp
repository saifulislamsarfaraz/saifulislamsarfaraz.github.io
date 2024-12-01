#include <bits/stdc++.h>
using namespace std;
int ara[100005];
int binarySearch(int ara[],int n,int value){
    int start = 0;
    int end = n;
    int mid;
    while (start<end)
    {
        mid = (start + end) /2;
        if(ara[mid]==value){
            return 1;
        }else if(ara[mid]<value){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return -1;
}
int main(){
    int n,sum;
    cin>>n>>sum;
    for(int i = 0; i < n; i++)cin>>ara[i];
    sort(ara,ara+n);
    int cnt = 0,cnt1 =0;
    for(int i = 0; i <= n; i++){
        int a = ara[i];
        int b = sum - a;
        if(a==b){
            cnt1++;
        }
        if(binarySearch(ara,i,b)==1){
            cnt++;
        }
    }
    cout<<cnt*cnt+cnt1<<""<<endl;
    return 0;
}
