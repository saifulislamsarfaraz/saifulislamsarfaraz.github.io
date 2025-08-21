#include<bits/stdc++.h>
using namespace std;
char s1[10005],s2[10005];
int dp[10005][10005];
int choice[10005][10005];
char f(int p1,int p2,int len1,int len2){
        if(s1[p1]==0)return len2 - p2;
        if(s2[p2]==0)return len1 - p1;
        if(dp[p1][p2]!=-1)return dp[p1][p2];
        if(s1[p1]==s2[p2])return dp[p1][p2] = f(p1+1,p2+1,len1,len2);
        int opIns = 1 + f(p1, p2+1,len1,len2);
        int opDlt = 1 + f(p1+1,p2,len1,len2);
        int opRep = 1 + f(p1+1,p2+1,len1,len2);
        if(opIns<=opDlt && opIns<=opRep){
            choice[p1][p2] = 1;
            return dp[p1][p2]=opIns;
        }
        else if(opDlt<=opIns && opDlt<=opRep){
            choice[p1][p2] = 2;
            return dp[p1][p2]=opDlt;
        }else{
        choice[p1][p2] = 3;
        return dp[p1][p2] = opRep;
        }
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
        int out = f(0,0,len1,len2);
        cout<<""<<out<<endl;

        int pos1 = 0;
        int pos2 = 0;


        while(true){
            if(pos1==len1){
                for(int i = pos2; i<len2; i++){
                    cout<<"insert "<<s2[i]<<" at position "<<i<<endl;
                    pos1++;
                }
            }
            else if(pos2==len2){
                for(int i = pos1; i < len1; i++){
                    cout<<"Delete "<<s1[i]<<" from position "<<i<<endl;
                    pos1++;
                }
            }else if(s1[pos1]==s2[pos2]){
                pos1++;
                pos2++;
            }else if(choice[pos1][pos2]==1){
                    cout<<"insert "<<s2[pos2]<<" at position "<<pos2<<endl;
                    pos2++;
            }else if(choice[pos1][pos2]==2){
                    cout<<"Delete "<<s1[pos1]<<" from position "<<pos1<<endl;
                    pos1++;
            }else{
                cout<<"Replace "<<s1[pos1]<<" with "<<s2[pos2]<<" at position "<<pos1<<endl;
                pos1++;
                pos2++;
            }
        }

        return 0;

}
