#include <bits/stdc++.h>
#define SIZE 200105
using namespace std;
struct edge
{
    int u, v, w;
} edges[SIZE];

bool cmp(edge a, edge b)
{
    return a.w>b.w;
}

int par[SIZE], sz[SIZE];

void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        par[i]=-1;
        sz[i]=1;
    }
}

int findRoot(int u)
{
    if(par[u]==-1)
        return u;
    return findRoot(par[u]);
}

int merger(int u, int v)
{
    u=findRoot(u);
    v=findRoot(v);
    if(u==v)
        return 0;
    if(sz[u]<sz[v])
        swap(u, v);
    par[v]=u;
    sz[u]=sz[v]+sz[u];
    return 1;
}


int mst(int n, int e)
{
    int sum=0;
    init(n);
    sort(edges, edges+e, cmp);
    for(int i=0; i<e; i++)
    {
        if(merger(edges[i].u, edges[i].v)==1)
        {
            sum+=edges[i].w;
        }
    }
    return sum;
}


int main()
{
    int u, v, w;
    int n, e;
    scanf("%d %d", &n, &e);
    for(int i=0; i<e; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        edges[i]= {u, v, w};
    }
    printf("%d\n", mst(n, e));
    return 0;
}
