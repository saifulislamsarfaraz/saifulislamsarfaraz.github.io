#include<bits/stdc++.h>
using namespace std;
int countLetter(string s){
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        bool flag = false;
        for(int j = 0; j < i; j++){
            if(s[i]==s[j]){
                flag = true;
                break;
            }
        }
        if(!flag)cnt++;
    }
    return cnt;
}
int main(){
    string s;
    cin>>s;
   // sort(s.begin(),s.end());
    int cnt = countLetter(s);
    int rem = s.length() - cnt;

    if(s.length()==1){
        cout<<""<<0<<endl;
    } else if(cnt==1){
       cout<<""<<cnt<<endl;
    }else{
        cout<<""<<rem + cnt/rem<<endl;
    }



}
