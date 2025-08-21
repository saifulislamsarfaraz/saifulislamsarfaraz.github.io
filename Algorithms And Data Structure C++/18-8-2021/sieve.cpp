#include<bits/stdc++.h>
using namespace std;
int nPrime=0;
int prime[1000000];
int mark[1000000];
void sieve(int n){
    int limit = sqrt(n)+1;
    for(int i = 4; i <= n;i+=2){
        mark[1];
    }
    prime[nPrime++] = 2;
     for(int i =3; i<=n;i+2){
        if(!mark[i]){
            prime[nPrime++] = i;

            if(i<=limit){
                for(int j = i*i; j<=n; i+=i*2){
                    mark[j] = 1;
                }
            }
        }
    }
}
int main(){

        int n;
        cin>>n;
        sieve(n);
        for(int i = 0; i<=nPrime;i++){
            cout<<prime[i]<<""<<endl;
        }

        return 0;

}
