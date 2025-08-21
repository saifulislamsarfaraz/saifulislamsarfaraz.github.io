#include<bits/stdc++.h>
using namespace std;
#define size_N 1000
#define size_P 1000

bool flag[size_N];
int primes[size_P];
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
        if(flag[i])
            primes[total++] = i;
    }
    return total;
}
int main(){
    int n;
    cin>>n;
    int total = seive(n);

    cout<<"Total Primes: "<<total<<endl;

    for(int i = 0; i < total; i++){
        cout<<primes[i]<<" ";
    }

    return 0;

}
