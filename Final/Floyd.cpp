#include <bits/stdc++.h>
#define SIZE 1005
#define INF 1000000000
using namespace std;
int adj[SIZE][SIZE];
int dis[SIZE][SIZE];
int path[SIZE][SIZE];
int n,m;
//4 7
//1 2 3
//2 1 8
//1 4 7
//4 1 2
//3 1 5
//2 3 2
//3 4 1
int Turn;
int CnodeD;
void Floyd(){
    for(int k = 1; k <=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j <=n; j++){
                Turn = dis[i][k]+dis[k][j];
                CnodeD = dis[i][j];
                if(Turn==INF){cout<<" turn INF ";}else
                cout<<" turn "<<Turn;
                if(CnodeD==INF){cout<<"<Cbode INF ";}else
                cout<<"< CnodeD "<<CnodeD;
                cout<<endl;
                if(dis[i][k]+dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = path[k][j];
                }
                if(dis[i][j]==INF){cout<<" INF ";}else
                cout<<" "<<dis[i][j];
            }
            cout<<endl;
        }
        cout<<"----"<<endl;
    }
}
int printPath(int path[][SIZE],int src,int m){

    if(path[src][m]==src)return src;
    printPath(path,src,path[src][m]);
    cout<<" "<<path[src][m];


}
int main(){

    cin>>n;
    cin>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj[i][j] = INF;
        }
    }
    int u,v,w;
    for(int i = 1; i <= m; i++){
        cin>>u>>v>>w;
        adj[u][v]=w;
    }
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=n; j++){
            if(i==j)dis[i][j]==0;
            else dis[i][j] = adj[i][j];
        }
    }
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(i==j) path[i][j] = 0;
            else if(path[i][j]!=INF){
                path[i][j] = i;
            }else
            path[i][j] = -1;
        }
    }
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=n; j++){
                if(dis[i][j]==INF){cout<<" INF ";}else
                cout<<" "<<dis[i][j];
        }
        cout<<endl;
    }
    cout<<"----"<<endl;
    Floyd();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i!=j && path[i][j]!=-1){
                cout<<"Total cost = "<<i<<" to "<<""<<j<<": "<<""<<dis[i][j]<<" Path: "<<i;
                printPath(path,i,j);
                cout<<" "<<j;
                cout<<endl;
            }
        }
    }
    return 0;
}
