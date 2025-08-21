#include<bits/stdc++.h>
using namespace std;
#define Uncolored -1
#define Red 200
#define Black 500
#define Nodes 100005
int n, e;
vector <long long int> adj[Nodes];
long long int col[Nodes];
long long int col2[Nodes];
queue <long long int> q;

long long int isBipartite(int src){
    long long int sum = 200;
    col[1] = Red;
    q.push(src);
    int u , v;
    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            v = adj[u][i];
            if(col[v]==-1){

                if(col[u]==Black){
                        col[v] = Red;
                        sum+=200;
                }
                else{
                col[v] = Black;
                sum+=500;

                }
                q.push(v);
            }
        }
    }

    return sum;
}
long long int isBipartite2(int src){
   long long int sum = 500;
    col2[1] = Black;
    q.push(src);
    int u , v;
    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            v = adj[u][i];
            if(col2[v]==-1){

                if(col2[u]==Red){
                        col2[v] = Black;
                        sum+=500;
                }
                else{
                col2[v] = Red;
                sum+=200;
                }
                q.push(v);
            }
        }
    }

    return sum;
}
int main(){
    int n,e;
    cin>>n;
    cin>>e;
    int u,v;
    for(int i = 0; i < e; i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        col[i] = Uncolored;
    }
    for(int i = 1; i <= n; i++){
        col2[i] = Uncolored;
    }
    long long int a = isBipartite(1);
    long long int b = isBipartite2(1);
    if(a<=b){
        cout<<""<<a<<endl;
    }else
    cout<<""<<b<<endl;



}

