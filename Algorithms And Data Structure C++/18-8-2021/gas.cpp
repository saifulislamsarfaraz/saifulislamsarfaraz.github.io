#include<bits/stdc++.h>
using namespace std;
int ara[1005];
int main(){

        int n,k;
        cin>>n;
        cin>>k;
        for(int i = 0; i < n; i++){
                cin>>ara[i];
        }
        sort(ara, ara + n);
        int rem = k - ara[n-1];
        int cnt = 1;
        for(int i = 0; i < n-1; i++){
            if(rem >= ara[i]){
                rem = rem - ara[i];
            }else if (rem < ara[i]){
                cnt++;
                rem = k;
                rem = rem - ara[i];
            }
        }
        cout<<""<<cnt<<endl;


//printf("Hello");

    return 0;
}
