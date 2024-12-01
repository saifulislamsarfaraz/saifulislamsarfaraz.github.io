#include <bits/stdc++.h>
#define SIZE 1000106
using namespace std;
int n, e;
vector <int> adj[SIZE];
int par[SIZE];
int dis[SIZE];
queue <int> q;
void bfs(int src){

    dis[src]=0;
    par[src]=src;
    q.push(src);
    int u, v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            v=adj[u][i];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &e);
    int u, v;
    for(int i=0; i<e; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)

    {
        dis[i]=100000000;
    }
    //int src;
    //scanf("%d", &src);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==100000000)
        {
            bfs(i);
            cnt++;
        }
    }
    int q=1;
    int s=0;
    if (cnt==1)
    {
       printf("%d",q);
    }
    else
    {
        printf("%d",s);

    }
    //printf("%d",cnt);
    //bfs(src);
    /*for(int i=1; i<=n; i++)
    {
        printf("Distance of node %d is %d\n", i, dis[i]);
    }*/
    return 0;
}

