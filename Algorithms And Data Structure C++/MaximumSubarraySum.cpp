#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ara[1005];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    int l;
    cin>>l;
    int max = 0;
    for(int i = 0; i < n; i++){
        int sum = 0,cnt = 0;
        for(int j = i; j < n; j++){
            sum+=ara[j];
            if(sum <= l){
                cnt++;
            }
        }
        if(cnt >= max){
            max = cnt;
        }
    }
    cout<<""<<max<<endl;
}
