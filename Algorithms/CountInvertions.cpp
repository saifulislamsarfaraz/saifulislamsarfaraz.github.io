#include<bits/stdc++.h>
using namespace std;

int marge(int ara[],int start,int mid,int end){
        int i = start;
        int j = mid+1;
        int combined[1005];
        int tempIndex = start;
        int invC = 0;
        while(i <= mid && j <= end){
            if(ara[i]<=ara[j]){
                combined[tempIndex++] = ara[i];
                i++;
            }else{
                combined[tempIndex++] = ara[j];
                 invC+=(end-mid);
                 //invC+=(mid-i+1);
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


int margeSort(int ara[],int start, int end){
        int invC = 0;
        if(start < end){
        int mid = (start + end)/2;

        invC +=(margeSort(ara,start,mid)+margeSort(ara,mid+1,end)+marge(ara,start,mid,end));
        }

        return invC;

}
int main(){
    int n,limit;
    int ara[1005];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    int ans = margeSort(ara,0,n-1);
    cout<<""<<ans<<endl;

}
