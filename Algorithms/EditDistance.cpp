#include<bits/stdc++.h>
using namespace std;
long long dp[105];
char s1[10005],s2[10005];
int dp[10005][10005];
char f(int p1,int p2,int len1,int len2){
        if(s1[p1]==0)return len2 - p2;
        if(s2[p2]==0)return len1 - p1;
        if(s1[p1]==s2[p2])return f(p1+1,p2+1,len1,len2);
        int opIns = 1 + f(p1, p2+1,len1,len2);
        int opDlt = 1 + f(p1+1,p2,len1,len2);
        int opRep = 1 + f(p1+1,p2+1,len1,len2);
        if(opIns<=opDlt && opIns<=opRep){
            return opIns;
        }
        if(opDlt<=opIns && opDlt<=opRep){
            return opDlt;
        }
        return opRep;
}

int main(){
        cin>>s1;
        cin>>s2;
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        for(int i = 0; i <=len1; i++){
            for(int j = 0; j <= len2; j++){
                dp[i][j] = -1;
            }
        }
        cout<<""<<f(0,0,len1,len2)<<endl;

        return 0;

}
