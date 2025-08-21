#include <bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;
vector <int> adj[1000005];
int color[1000005];
int n,e;
int c=1;

void dfs(int u)
{

    color[u]=GREY;
    int g,v;
    for(int i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(color[v]==WHITE)
        {
             dfs(v);
        }

        else if(color[v]==GREY)
        {
            c=0;
        }
    }
    color[u]=BLACK;
}
int main()
{
    scanf("%d %d", &n, &e);
    int u,v;
    for(int i=1; i<=e; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for(int i=1; i<=n; i++)
    {
        color[i]=WHITE;
    }

    for(int i=1; i<=n; i++)
    {
        if(color[i]==WHITE)
        {
            dfs(i);
        }
    }
   if(c==0)
    {

      printf("no");
    }
    else
    {

      printf("yes");
    }

    return 0;
}
