#include<bits/stdc++.h>
using namespace std;
int n,e;
vector <int> adj[100005];
int dis[100005];
int mx,val;
queue<int> q;
void bfs(int s)
{
    for(int i=0;i<=n;i++)
    {
        dis[i]=-1;
    }
    dis[s]=0;
    q.push(s);
    int u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(dis[v]==-1)
            {
                q.push(v);
               dis[v]=dis[u]+1;

            }
        }
    }

}

int main()
{
    int u,v,s=1,mx=0;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++)
    {
       scanf("%d %d",&u,&v);
       adj[u].push_back(v);
       adj[v].push_back(u);
    }

    bfs(s);
    for(int i=0;i<=n;i++)
    {
        val=max(dis[i],dis[i+1]);
        if(mx<val)mx=val;
    }
    printf("%d\n",mx);
    return 0;
}
