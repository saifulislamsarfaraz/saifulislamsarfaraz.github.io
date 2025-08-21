#include<bits/stdc++.h>
using namespace std;

int maxCrossingSum(int ara[], int l, int m, int h,int limit){

    int sum = 0;
    int left_cnt = 0;
    for(int i = m; i >=l; i--){
        sum = sum + ara[i];
        if(sum <= limit){
            left_cnt++;
        }
    }

    sum = 0;
    int right_cnt = 0;
    for(int i = m + 1; i <=h; i++){
        sum = sum + ara[i];
        if(sum <= limit){
            right_cnt++;
        }
    }
    int left_or_right_max = max(left_cnt,right_cnt);
    int left_plus_right = left_cnt + right_cnt;
    if(left_plus_right<=limit){
        return left_plus_right;
    }else{
        return left_or_right_max;
    }
}

int maxSubArraySum(int ara[],int low,int high,int limit){
        int araSize = sizeof(ara);
        if(low==high){
            return ara[high];
        }

        int mid = (low + high)/2;
        int left_or_right_max = max(maxSubArraySum(ara,low,mid,limit),maxSubArraySum(ara,mid+1,high,limit));
        int max_crossing = maxCrossingSum(ara,low,mid,high,limit);
        if(max_crossing<=limit){
            return max_crossing;
        }else{
            return left_or_right_max;
        }

}
int main(){
    int n,limit;
    int ara[1005];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    cin>>limit;
    int max_sum = maxSubArraySum(ara,0,n-1,limit);


    cout<<""<<max_sum<<endl;
}
