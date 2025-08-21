#include<bits/stdc++.h>
using namespace std;
int occoure(string a, string b){
        int i = 0;
        int j = 0;
        int al = a.length();
        int bl = b.length();
        int cnt = 0;
        while (j < bl){
            if(a[i]==b[j]){
                cnt++;
                i++;
                j++;
            }else if(a[i]>b[j]){
                j++;
            }else{
                i++;
            }
        }
        return cnt;
}

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int bl = b.length();
    int cnt = occoure(a,b);
    if(cnt==bl) cout<<"1"<<endl;
    else cout<<"0"<<endl;


}
