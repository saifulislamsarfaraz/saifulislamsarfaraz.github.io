//Md Saiful
//Id: 2019-2-60-040

#include <bits/stdc++.h>
#define SIZE 100105
#define INF 1000000000
int par[SIZE];
using namespace std;
struct element{
    int node=0, weight=0;
    element(){}

    element(int n, int w){
        node=n;
        weight=w;
    }
    bool operator <(const element &a)const{
        return weight<a.weight;
    }
    bool operator >(const element &a)const{
        return weight>a.weight;
    }
};

priority_queue <element, vector <element>, greater <element> > pq;
int dis[SIZE];
bool vis[SIZE];
vector <int> adj[SIZE];
vector <int> adjw[SIZE];
int n, e;
//7 12
//1 2 4
//1 6 5
//2 7 1
//2 3 2
//3 7 3
//3 4 10
//4 5 6
//5 6 1
//7 1 2
//7 4 2
//7 5 4
//7 6 8
void dijkstra(int source){
    par[source] = -1;
    pq.push(element(source, 0));
    int u, v, w,sum;
    while(!pq.empty()){
        u=pq.top().node;
        cout<<"node pop: "<<u<<endl;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0; i<(int)adj[u].size(); i++){
            v=adj[u][i];
            sum = dis[u] + adjw[u][i];
            cout<<" "<<u<<", to "<<v<<"sum "<<sum<<" is less "<<dis[v];
            if(dis[u]+adjw[u][i]<dis[v]){
                par[v] = u;
                dis[v]=dis[u]+adjw[u][i];
                pq.push(element(v, dis[v]));
                cout<<" push NW:("<<v<<","<<dis[v]<<")";
            }
        }
        cout<<endl;
        cout<<"index: ";
        for(int i=1; i<=n; i++){
            cout<<" "<<i;
        }
        cout<<endl;
        cout<<"Dis:  ";
        for(int i=1; i<=n; i++){
            cout<<" "<<dis[i];
        }
        cout<<endl;
        cout<<"vis:  ";
        for(int i=1; i<=n; i++){
            cout<<" "<<vis[i];
        }
        cout<<endl;
    }
}
//a = 1
//b = 2
//c = 3
//d = 4
//e = 5
//f = 6

int pathPrint(char a[], int des){
       if(par[des]==-1){
        return des;
       }
       pathPrint(a, par[des]);

       cout<<" ->"<<a[des]<<" cost: "<<dis[des];
}

int main(){
    char a[] = {'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'};
    int u, v, w;
    scanf("%d %d", &n, &e);

    for(int i=0; i<e; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(v);
        adjw[u].push_back(w);
    }
    for(int i=1; i<=n; i++){
        dis[i]=INF;
        vis[i]=false;
    }
    dis[1]=0;
    dijkstra(1);
    for(int i = 1; i<=n; i++){
        printf("a to %c total cost = %d path a ",a[i], dis[i]);

        pathPrint(a, i);
        cout<<endl;
    }
    return 0;
}
