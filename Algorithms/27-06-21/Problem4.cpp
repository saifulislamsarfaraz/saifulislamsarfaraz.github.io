#include <bits/stdc++.h>
using namespace std;
int ara[100005];
int main(){
    int n,sum;
    cin>>n>>sum;
    for(int i = 0; i < n; i++)cin>>ara[i];

    int cnt1=0;

    for(int i = 0; i < n; i++){
       for(int j = 0; j <n; j++){
        long long int a = ara[i] + ara[j];
        if(a==sum){
            cnt1++;
         }
       }
    }
    cout<<cnt1<<""<<endl;
    return 0;
}
