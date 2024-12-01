#include<bits/stdc++.h>
using namespace std;

int maxMin(int ara[],int n){
    int max = ara[0];
    int min = ara[0];
    int cnt = 1;
    for(int i= 0; i <n; i++){
        if(ara[i]>max){
            cnt++;
            max = ara[i];
        }
    }
    return cnt;

}
int main(){
    int t,n;
    int ara[1005];
    cin>>t;
    while(t>0){
        cin>>n;
         for(int i = 0; i < n; i++) cin>>ara[i];
         cout<<""<<maxMin(ara,n);
         t--;
    }
}

