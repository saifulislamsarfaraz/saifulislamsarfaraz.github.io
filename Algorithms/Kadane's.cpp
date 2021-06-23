#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ara[1005];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];

    int meh = 0,cnt = 0;
    int msf = INT_MIN;
    for(int i = 0; i < n; i++){
            meh = meh + ara[i];
            if(msf < meh){//if maximum so far is less than maximum ending here maximum so far will be maximum ending here 
                msf = meh;
            }
            if(meh < 0){//if maximum ending here is less than zero than make it zero
                meh = 0;
            }
    }
    cout<<""<<msf<<endl;
}
