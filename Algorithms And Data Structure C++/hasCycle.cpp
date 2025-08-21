#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int> adj[100005];
int col[100005];
int discover[100005];
int finising[100005];
int timeCounter = 0;
bool hasCycle = false;
void dfs(int u){
    col[u] = GREY;
    discover[u] = timeCounter;
    timeCounter++;
    int v;
    for(int i = 0; i < adj[u].size(); i++){
        v = adj[u][i];
        if(col[v]==WHITE){
            dfs(v);
        }else if(col[v]==GREY){
            hasCycle = true;
        }
    }
    col[u] = BLACK;
    finising[u] = timeCounter;
    timeCounter++;
}
int main(){
    int n,e;

    cin>>n;
    cin>>e;
    int u,v;
    for(int i = 0; i < e; i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        col[i] = WHITE;
    }

    for(int i = 1; i <= n; i++){
            if(col[i]==WHITE)
                dfs(i);
    }
    if(hasCycle==true){
        cout<<"no"<<endl;
    }else{
        cout<<"yes"<<endl;
    }

}
