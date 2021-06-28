#include<bits/stdc++.h>
using namespace std;
long long int combined[10000005];
void marge(long long int ara[],long long int start,long long int mid,long long int end){
        long long int i = start;
        long long int j = mid+1;
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
void margeSort(long long int ara[],long long int start,long long int end){

        if(start < end){
        long long int mid = (start + end)/2;
        margeSort(ara,start,mid);
        margeSort(ara,mid+1,end);
        marge(ara,start,mid,end);
        }

}
long long int countPairs(long long int ara[],long long int n,long long int sum){

    map<long long int,long long int>m;
    long long int cnt = 0;
    for(int i = 0; i < n; i++){
        m[ara[i]]++;
    }
    for(int i=0; i< n; i++){

         cnt += m[sum-ara[i]];

    }
    return cnt;
}
long long int ara[1000005];
int main(){
    long long int n,sum;
    cin>>n>>sum;
    for(int i = 0; i < n; i++) cin>>ara[i];
    margeSort(ara,0,n-1);
    long long int cnt = countPairs(ara,n,sum);

    cout<<""<<cnt<<endl;
}
