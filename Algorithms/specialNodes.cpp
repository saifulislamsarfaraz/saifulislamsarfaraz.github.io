#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int> adj[100005];
vector<int> transpose[100005];
vector<int> transpose2[100005];
int col[100005];
int discover[100005];
int finising[100005];
int timeCounter = 0;
stack<int> s;
queue<int> q;
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
    int v;
    for(int i = 0; i < transpose[u].size(); i++){
        v = transpose[u][i];
        if(col[v]==WHITE){
            dfs2(v);
        }
    }
    col[u] = BLACK;
}
void dfs3(int u){
    col[u] = GREY;
    discover[u] = timeCounter;
    timeCounter++;
    int v;
    for(int i = 0; i < transpose2[u].size(); i++){
        v = transpose2[u][i];
        if(col[v]==WHITE){
            dfs3(v);
        }
    }
    col[u] = BLACK;
    finising[u] = timeCounter;
    timeCounter++;
}
int main(){
    int n,e;
    int cnt = 0,cnt2=0;
    cin>>n;
    cin>>e;
    int u,v;
    for(int i = 0; i < e; i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        transpose[v].push_back(u);
        transpose2[v].push_back(u);
        transpose2[u].push_back(v);
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
            q.push(a);
            dfs2(a);
        }
    }


    for(int i = 1; i <= n; i++){
        col[i] = WHITE;
    }
    for(int i = 1; i<=n;i++){
        if(col[i]==WHITE){
            cnt2++;
            dfs3(i);
        }
    }

    for(int i = 1; i <= n; i++){
        col[i] = WHITE;
    }
   // cout<<q.size()<<endl;
   //1 5 4 8
   if(cnt2>1){
    cout<<0<<endl;
   }else{
    int a = q.front();
    dfs2(a);
    for(int i = 0; i <=n; i++){
        if(col[i]==BLACK){
            cnt++;
        }

    }

        cout<<cnt<<endl;
   }
}
