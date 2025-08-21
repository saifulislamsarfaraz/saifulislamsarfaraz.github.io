#include <bits/stdc++.h>
using namespace std;
bool prime[10000001];
void solve(int n){
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i <= n; i++){
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==true && i*i<=n){
            cout<<i*i<<" ";
        }
    }
}

int main()
{

    
    int n;
    cin>>n;
    if(n<4){
        cout<<"No Almost Prime Number"<<endl;
    }
    else{
        solve(n);
    }
}