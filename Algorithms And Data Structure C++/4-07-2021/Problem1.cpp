#include<bits/stdc++.h>
using namespace std;
long long int combined[1000005];
long long int marge(long long int ara[],long long int start,long long int mid,long long int end){
        long long int i = start;
        long long int j = mid+1;

        int tempIndex = start;
        long long int invC = 0;
        while(i <= mid && j <= end){
            if(ara[i]<=ara[j]){
                combined[tempIndex++] = ara[i];
                i++;
            }else{
                combined[tempIndex++] = ara[j];
                 invC+=(mid-i+1);
                 j++;
            }
        }

        while(i <= mid){
            combined[tempIndex++] = ara[i];
            i++;
        }

        while(j <= end){
            combined[tempIndex++] = ara[j];
            j++;
        }

        for(int i = start; i<=end; i++){
            ara[i] = combined[i];
        }
        return invC;

}


long long int margeSort(long long int ara[],long long int start,long long int end){
        long long int invC = 0;
        if(start < end){
        int mid = (start + end)/2;

        invC +=(margeSort(ara,start,mid)+margeSort(ara,mid+1,end)+marge(ara,start,mid,end));
        }
        return invC;

}
long long int ara[1000005];
int main(){
    int n;

    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    long long int ans = margeSort(ara,0,n-1);
    cout<<""<<ans<<endl;

}
