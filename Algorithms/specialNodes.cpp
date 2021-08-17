#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int> adj[100005];
vector<int> transpose[100005];
int col[100005];
int discover[100005];
int finising[100005];
int timeCounter = 0;
stack<int> s;
void dfs1(int u){
    col[u] = GREY;
    int v;
    for(int i = 0; i < adj[u].size(); i++){
        v = adj[u][i];
        if(col[v]==WHITE){
            dfs1(v);
        }
    }
    col[u] = BLACK;
    s.push(u);
}
void dfs2(int u){
    col[u] = GREY;
    discover[u] = timeCounter;
    timeCounter++;
    int v;
    for(int i = 0; i < transpose[u].size(); i++){
        v = transpose[u][i];
        if(col[v]==WHITE){
            dfs2(v);
        }
    }
    col[u] = BLACK;
    finising[u] = timeCounter;
    timeCounter++;

}
int main(){
    int n,e;
    int cnt = 0;
    cin>>n;
    cin>>e;
    int u,v;
    for(int i = 0; i < e; i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        col[i] = WHITE;
    }

    for(int i = 1; i <= n; i++){
            if(col[i]==WHITE)
                dfs1(i);
    }
    for(int i = 1; i <= n; i++){
        col[i] = WHITE;
    }

    for(int i = 1; i <=n; i++){
        int a = s.top();
         s.pop();
        if(col[a]==WHITE){
            cnt++;
        dfs2(a);
        if(finising[a]==1){
            cout<<a<<endl;
            }
        }

    }

//    for(int i = 1; i <=n; i++){
//             //cout<<discover[i]<<""<<finising[i]<<""<<endl;
//        if(finising[i]==1 && discover[i]==0){
//            cout<<i<<endl;
//             break;
//        }
//
//    }
   // cout<<cnt<<endl;
}
