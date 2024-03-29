#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int> adj[100005];
vector<int> transpose[100005];
int col[100005];
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
    int v;
    for(int i = 0; i < transpose[u].size(); i++){
        v = transpose[u][i];
        if(col[v]==WHITE){
            dfs2(v);
        }
    }
    col[u] = BLACK;
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
        }

    }
    cout<<cnt<<endl;
}
