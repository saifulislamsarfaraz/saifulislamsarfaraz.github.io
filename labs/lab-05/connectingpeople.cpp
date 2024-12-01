#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
queue<int> q;
int dis[100010];
int n;
int ct=-1;

void bfs(int s)
{
    dis[s]=1;
    q.push(s);

    int u,v;
    while(!q.empty())
    {

        u =q.front();
        q.pop();
        
    
        for(int i=0; i<adj[u].size(); i++)
        {
            v= adj[u][i];
            if(dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    int u,v;
    for(int i=0; i<e; i++)
    {
        scanf("%d %d", &u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    for(int j=1; j<=n; j++){
    	dis[j]=-1;
	}
   for(int j=0;j<=n;j++){

		if(dis[j]==-1)
		{
            ct++;
            bfs(j);
        }
    }

	printf("%d",ct);
	return 0;
}

