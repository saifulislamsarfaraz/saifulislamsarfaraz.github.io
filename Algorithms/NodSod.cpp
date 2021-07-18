#include<bits/stdc++.h>
using namespace std;
int ara[1000005];
int sod[1000005];
int nod[1000005];
int main(){

    int n;
    cin>>n;
    int cnt = 0;
    for(int i = 0; i <= n; i++){
        nod[i] = 0;
        sod[i] = 0;
    }
    for(int i = 1; i <=n; i++){
        for(int j = i; j <= n; j+=i){
            nod[j]++;
            sod[j]+=i;
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<nod[i]<<" ";
        cout<<sod[i]<<endl;
    }

    return 0;
}

