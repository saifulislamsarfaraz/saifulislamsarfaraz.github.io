#include<bits/stdc++.h>
using namespace std;


bool flag[10000000];
int primes[10000000];
int seive(int n){
    int total = 0;
    for(int i = 0; i <= n; i++){
        flag[i] = 1;
    }
    int value = sqrt(n) + 1;

    for(int i = 2; i < value; i++){
        if(flag[i]!=0)
        for(int j = i; j*i <= n; j++){
            flag[i*j] = 0;
        }
    }

    for(int i = 2; i  <= n; i++){
        if(flag[i]==1)
            primes[total++] = i;
    }
    return total;
}

int main(){
    int n;
    cin>>n;
    int total = seive(n);
    for(int i = 0; i < total; i++){
        cout<<primes[i]<<endl;
    }

    return 0;

}
