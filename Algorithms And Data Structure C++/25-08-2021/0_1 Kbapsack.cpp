#include<bits/stdc++.h>
using namespace std;
struct Box{
    int w;
    int v;
};

Box b[10005];
int n;
int total_cap;
int dp[10005][10005];
int best_choice[10005][10005];

int f(int no,int rem){

    if(no==n) return 0;

    int op0,op1=0;
    op0 = f(no+1,rem);

    if(dp[no][rem]!=-1) return dp[no][rem];

    if(b[no].w<=rem){
        op1 = b[no].v + f(no+1, rem - b[no].w);
    }

    if(op0>=op1){
        best_choice[no][rem] = 0;
        return dp[no][rem] = op0;
    }

    else{
    best_choice[no][rem] = 1;
    return dp[no][rem] = op1;

    }

}

int main(){
    cin>>n;
    cin>>total_cap;
    for(int i = 0; i < n; i++){
        cin>>b[i].w;
        cin>>b[i].v;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j<= total_cap; j++){
            dp[i][j] = -1;
        }
    }
    cout<<""<<f(0,total_cap)<<endl;


    int curr_box = 0;
    int curr_cap = total_cap;

        while(curr_box<n){

            if(best_choice[curr_box][curr_cap]==1 && b[curr_box].w<=curr_cap){
                cout<<"Take box "<<curr_box+1<<endl;
                curr_cap = curr_cap - b[curr_box].w;


            }else{
            curr_box++;
            }
        }

    return 0;
}
