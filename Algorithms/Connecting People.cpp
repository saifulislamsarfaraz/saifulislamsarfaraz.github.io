#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int dis[100005];
queue <int> q;
void bfs(int src){
    dis[src] = 0;
    q.push(src);
    int u,v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            v = adj[u][i];
            if(dis[v]==-1){
                dis[v] = 1 + dis[u];
                q.push(v);
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n;
    cin>>e;
    int u,v;
    for(int i = 0; i < e; i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        dis[i] = -1;
    }
    int cnt = -1;
    for(int i = 0; i <= n; i++){
            if(dis[i]==-1){
                cnt++;
                bfs(i);
            }
    }
    cout<<""<<cnt<<endl;
}