#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int> adj[100005];
int col[100005];
int d[100005];
int low[100005];
int timeCounter = 0;
void dfs(int u,bool isRoot){
    col[u] = GREY;
    timeCounter++;
    d[u] = timeCounter;
    low[u] = d[u];
    int v;
    bool isArtiulationPoint= false;
    int childCount = 0;
    for(int i = 0; i < adj[u].size(); i++){
           v = adj[u][i];
           if(col[v]==WHITE){
            dfs(v,false);
            if(low[v]>=d[u]){
                isArtiulationPoint = true;
            }
            if(low[v]<low[u])low[u] = low[v];
            if(low[v]>d[u]) cout<<""<<u<<","<<v<<"is a bridge"<<endl;
                childCount++;
        }
        if(col[v]==GREY){
            if(d[v]<low[u])low[u]=d[v];
        }
    }
    if(isRoot&&childCount>1)cout<<""<<u<<" is an articulation point"<<endl;
    else if(!isRoot && isArtiulationPoint)cout<<""<<u<<" is an articulation point"<<endl;
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

    dfs(1,true);
//    for(int i = 1; i <= n; i++){
//            if(col[i]==WHITE)
//                dfs(i);
//    }

    return 0;
}

