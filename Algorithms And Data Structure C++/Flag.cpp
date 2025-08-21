#include<bits/stdc++.h>
using namespace std;
long long dp[105];
long long way(int n){
    if(n == 1)return 2;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = way(n-1) + way(n-2);
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    cout<<""<<way(n)<<endl;
    return 0;
}
