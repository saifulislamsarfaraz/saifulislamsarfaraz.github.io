#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int main(){

    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }
    for(int i = 0; i < n; i++){
        if(ara[i]==1){
            cout<<""<<1<<" "<<0<<endl;
        }else{
        int a = ara[i]/3;
        if(ara[i]%3!=0){
        if(a+((a+1)*2)==ara[i])
        cout<<""<<a<<" "<<a+1<<endl;
        else
        cout<<""<<a+1<<" "<<a<<endl;
        }else{
            cout<<""<<a<<" "<<a<<endl;
        }
        }
    }


    return 0;
}
