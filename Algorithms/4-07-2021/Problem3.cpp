#include<bits/stdc++.h>
using namespace std;

long long int  ara[1000005];
int main(){
    int n;
    long long int limit;

    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    cin>>limit;
    long long int max_sum = maxSubArraySum(ara,0,n-1,limit);

    cout<<""<<max_sum<<endl;
}
