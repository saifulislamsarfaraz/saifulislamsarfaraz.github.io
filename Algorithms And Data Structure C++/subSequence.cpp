#include<bits/stdc++.h>
using namespace std;
int occoure(string a, string b){
        int i = 0;
        int j = 0;
        int al = a.length();
        int bl = b.length();
        while(i<al && j < bl){
            if(a[i]==b[j]){
                j++;
            }
            if(bl==j){
                return 1;
            }
            i++;
        }
        return 0;
}

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int bl = b.length();
    int cnt = occoure(a,b);
    cout<<""<<cnt<<endl;


}
