#include<bits/stdc++.h>
using namespace std;

int maxCrossingSum(int ara[], int l, int m, int h){

    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = m; i >=l; i--){
        sum = sum + ara[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;

    for(int i = m + 1; i <=h; i++){
        sum = sum + ara[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }

    return max(left_sum + right_sum,max(left_sum,right_sum));

}

int maxSubArraySum(int ara[],int low,int high){
        int araSize = sizeof(ara);
        if(low==high){
            return ara[high];
        }

        int mid = (low + high)/2;

        return max(max(maxSubArraySum(ara,low,mid),maxSubArraySum(ara,mid+1,high)),maxCrossingSum(ara,low,mid,high));

}
int main(){
    int n;
    int ara[1005];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];

    int max_sum = maxSubArraySum(ara,0,n-1);


    cout<<""<<max_sum<<endl;
}
