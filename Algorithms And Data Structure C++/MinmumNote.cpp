#include<bits/stdc++.h>
using namespace std;
int ara[1005];
int main(){
    int ara[8] = {500,100,50,20,10,5,2,1};
    int n;
    cin>>n;
    int cnt = 0;
    int rem = n;
    for(int i = 0; i<8;i++){
        while(n>=ara[i]){
            cnt++;
            n-=ara[i];
        }
    }
    cout<<""<<cnt<<endl;
    return 0;
}
