#include<bits/stdc++.h>
using namespace std;

void marge(int ara[],int start,int mid,int end){
        int i = start;
        int j = mid+1;
        int combined[1005];
        int tempIndex = start;
        while(i <= mid && j <= end){
            if(ara[i]<ara[j]){
                combined[tempIndex++] = ara[i];
                i++;
            }else{
                combined[tempIndex++] = ara[j];
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

}


void margeSort(int ara[],int start, int end){

        if(start < end){
        int mid = (start + end)/2;
        margeSort(ara,start,mid);
        margeSort(ara,mid+1,end);
        marge(ara,start,mid,end);
        }



}
int main(){
    int n,limit;
    int ara[1005];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    margeSort(ara,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<""<<ara[i]<<endl;
    }
}
