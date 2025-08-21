#include<bits/stdc++.h>
using namespace std;
int dp[105];
int way(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    if(dp[n]!=-1)return dp[n];

    return dp[n] = (way(n-1)*2) + (way(n-2)*3);
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    cout<<""<<way(n)<<endl;
    for(int i = 0; i <= n; i++){
        cout<<""<<dp[i]<<endl;
    }

    return 0;
}
