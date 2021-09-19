#include <bits/stdc++.h>
#define SIZE 1000005
using namespace std;
int par[SIZE];
int sz[SIZE];
int n, e;
struct Edge{
    int u, v, w;
} Edges[SIZE];

bool compare(Edge a, Edge b){
    return a.w<b.w;
}

int findRoot(int u){
    if(par[u]==-1)
        return u;
    return findRoot(par[u]);
}

int mergeSet(int u, int v){
    u=findRoot(u);
    v=findRoot(v);
    if(u==v){
    return 0;
    }
    if(sz[u]>=sz[v]){
        par[v] = u;
        sz[u] = sz[u] + sz[v];
    }else{
    par[u]=v;
    sz[v]=sz[v]+sz[u];
    }
    cout<<"index: ";
    for(int j=1; j<=n;j++){
        cout<<j<<" ";
    }
    cout<<endl;
    cout<<"par:  ";
    for(int j=1; j<=n;j++){
        cout<<" "<<par[j];
    }
    cout<<endl;
    cout<<"Sz:  ";
    for(int j=1; j<=n;j++){
        cout<<" "<<sz[j];
    }
    cout<<endl;
    cout<<"-----***-----"<<endl;
    return 1;
}
int main(){
    int sum=0;
    int u, v, w;

    cin>>n>>e;
    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        Edges[i]= {u, v, w};
    }
    for(int i=1; i<=n; i++){
        par[i]=-1;
        sz[i]=1;
    }
    sort(Edges, Edges+e, compare);//sort ascending order
    for(int i=0; i<e; i++){
        if(mergeSet(Edges[i].u, Edges[i].v)==1){
            sum+=Edges[i].w;

        }
    }
    cout<<"----------"<<endl;
    cout<<"index: ";
    for(int j=1; j<=n;j++){
        cout<<j<<" ";
    }
    cout<<endl;
    cout<<"par: ";
    for(int j=1; j<=n;j++){
        cout<<" "<<par[j];
    }
    cout<<endl;
    cout<<"Sz: ";
    for(int j=1; j<=n;j++){
        cout<<" "<<sz[j];
    }
    cout<<endl;
    cout<<"Cost: "<<sum;
    return 0;
}

