#include <bits/stdc++.h>
#define SIZE 1000000
using namespace std;
int n, e,c1=0,c2=0;
vector <int> adj[SIZE];
int par[SIZE];
int dis[SIZE];
queue <int> q;
void bfs(int src)
{
    dis[src]=1;
    c1++;
    q.push(src);
    int u, v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i];
            if(dis[v] == 0)
            {
                if(dis[u]==1)
                {
                    dis[v]=2;
                    c2++;
                }
                else
                {
                    dis[v]=1;
                    c1++;
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &e);
    int u, v;
    for(int i=0; i<e; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        dis[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        if(dis[i]==0)
        {
            bfs(i);
        }
    }
    if(c1<c2)
    {
        c2 = c2 * 200;
        c1 = c1 * 500;
    }
    else
    {
        c2 = c2 * 500;
        c1 = c1 * 200;
    }
    cout<< c1+c2 <<endl;
}
