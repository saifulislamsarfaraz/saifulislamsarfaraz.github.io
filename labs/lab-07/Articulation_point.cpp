#include <bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
#define SIZE 100105
using namespace std;

vector <int> adj[SIZE];
int d[SIZE], low[SIZE], par[SIZE];
int color[SIZE];
int tme=0;
int c=0;

void dfs(int node, bool isRoot)
{
    tme++;
    d[node]=tme;
    low[node]=tme;
    color[node]=GREY;
    int v;
    int treeEdgeCount=0;
    bool isArticulationPoint=false;
    for(int i=0; i<adj[node].size(); i++)
    {
        v=adj[node][i];
        if(v==par[node])
            continue;
        if(color[v]==WHITE)
        {
            treeEdgeCount++;
            par[v]=node;
            dfs(v, false);
            if(low[v]>=d[node])
            {
                isArticulationPoint=true;
            }
        }
        low[node]=min(low[node], low[v]);
    }
    if(isRoot)
    {
        if(treeEdgeCount>=2)
            c++;
    }
    else if(isArticulationPoint)
       c++;
    color[node]=BLACK;
}

int main()
{
    int n, e, u, v;
    scanf("%d %d", &n, &e);
    while(e--)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(color[i]==WHITE)
        {
            dfs(i, true);
        }
    }
    printf("%d",c);
    return 0;
}
