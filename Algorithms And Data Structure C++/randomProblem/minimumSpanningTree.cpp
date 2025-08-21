#include <bits/stdc++.h>
#define SIZE 1000105
using namespace std;
int par[SIZE], sz[SIZE];
struct edge
{
    int u, v, w;
} edges[SIZE];

bool cmp(edge a, edge b){
    return a.w>b.w;
}

int findRoot(int u){
    if(par[u]==-1)
        return u;
    return findRoot(par[u]);
}

int mergetree(int u, int v){
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


int mst(int n, int e){
    int sum=0;
    sort(edges, edges+e, cmp);
    for(int i=0; i<e; i++){
        if(mergetree(edges[i].u, edges[i].v)==1){
            sum+=edges[i].w;
        }
    }
    return sum;
}


int main(){
    int u, v, w;
    int n, e;
    scanf("%d %d", &n, &e);
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &u, &v, &w);
        edges[i]= {u, v, w};
    }
        for(int i=1; i<=n; i++){
        par[i]=-1;
        sz[i]=1;
    }
    printf("%d\n", mst(n, e));
    return 0;
}
