#include<bits/stdc++.h>
using namespace std;
int memo[10005];
int f(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    if(memo[n]!=-1)return memo[n];
    return memo[n] = f(n-1) + f(n-2);
}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<20; i++){
        memo[i] = -1;
    }
    int nth = f(n);
    cout<<""<<nth<<endl;

}

/*
#include<bits/stdc++.h>
using namespace std;
int memo[10005];
int f(int n){
    if(n<=1) return n;

    if(memo[n]!=-1){
            printf("%d\n",memo[n]);
            return memo[n];
    }
    return memo[n] = f(n-1) + f(n-2);

}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<20; i++){
        memo[i] = -1;
    }
    int nth = f(n);
    cout<<""<<nth<<endl;

}


#include<bits/stdc++.h>
using namespace std;
int memo[10005];
int f(int n){
    if(n<=1) return n;

    if(memo[n]!=-1){
        if(memo[n]%2==0)
            printf("%d\n",memo[n]);
            return memo[n];
    }
    return memo[n] = f(n-1) + f(n-2);

}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<20; i++){
        memo[i] = -1;
    }
    int nth = f(n);
    cout<<""<<nth<<endl;

}

*/



