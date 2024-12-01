#include<bits/stdc++.h>
using namespace std;
int combined[1000005];
int marge(int ara[],int start,int mid,int end,int sum){
        int i = start;
        int j = mid+1;
        int tempIndex = start;
        int cnt = 0;
        while(i <= mid && j <= end){
            if(ara[i]<ara[j]){
                if(ara[i] + ara[j]==sum){
                    cnt++;
                }
                combined[tempIndex++] = ara[i];
                i++;
            }else{
                if(ara[i]+ara[j]==sum){
                    cnt++;
                }
                combined[tempIndex++] = ara[j];
                j++;
            }
        }

        while(i <= mid){
            if(ara[i] + ara[j] == sum){
                cnt++;
            }
            combined[tempIndex++] = ara[i];
            i++;
        }

        while(j <= end){
            if(ara[i] + ara[j]==sum){
                cnt++;
            }
            combined[tempIndex++] = ara[j];
            j++;
        }

        for(int i = start; i<=end; i++){
            ara[i] = combined[i];
        }
        return cnt;
}


int margeSort(int ara[],int start, int end,int sum){
        int cnt = 0;
        if(start < end){
        int mid = (start + end)/2;

        cnt +=(margeSort(ara,start,mid,sum) +
        margeSort(ara,mid+1,end,sum) +
          marge(ara,start,mid,end,sum));
        }
    return cnt;
}
int ara[1000005];
int main(){
    int n,sum;
    cin>>n>>sum;
    for(int i = 0; i < n; i++) cin>>ara[i];
     int cnt = margeSort(ara,0,n-1,sum);

    cout<<cnt<<endl;
}

