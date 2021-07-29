#include<bits/stdc++.h>
using namespace std;
int price[10005];
int dp[10005];
int f(int len){
  if(len == 0)return 0;
  if(dp[len]!=-1) return dp[len];

  int max = 0;
  int value;

  for(int i = 1; i <= len; i++){
        value  = price[i] + f(len - i);
        if(value>max) max = value;
  }

  return dp[len] = max;

}


int main(){

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){

        cin>>price[i];
        dp[i] = -1;
    }

    cout<<""<<f(n)<<endl;

}
