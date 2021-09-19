//Md Saiful
//Id: 2019-2-60-040

#include <bits/stdc++.h>
#define SIZE 100105
#define INF 1000000000
using namespace std;
int dis[SIZE];
int par[SIZE];
vector <int> adj[SIZE];
vector <int> adjw[SIZE];
int n, e;
//6 9
//1 2 10
//1 3 20
//2 4 50
//2 5 10
//3 5 33
//3 4 20
//4 5 20
//4 6 2
//5 6 1

//5 8
//1 2 -1
//1 3 4
//2 3 3
//2 4 2
//2 5 2
//5 4 -3
//4 3 5
//4 2 1


//6 9
//a b 10
//a c 20
//b d 50
//b e 10
//c e 33
//c d 20
//d e 20
//d e 2
//e f 1
void init(int source){
    for(int i = 1; i <=n; i++){
        dis[i] = INF;
        par[i] = -1;
    }
    dis[source] = 0;
}
void Ballman(int source){
        init(source);
        par[source] = -1;
        int v;
        int sum;
   for(int i = 1; i<e;i++){
        for(int u=1; u<=n; u++){
            cout<<"itteret "<<u<<endl;
            for(int j=0; j<(int)adj[u].size(); j++){
                v=adj[u][j];
                sum = dis[u]+adjw[u][j];
                cout<<" is sum less? "<<sum<<" this sum "<<dis[v]<<endl;
                if(dis[u]+adjw[u][j]<dis[v]){
                par[v] = u;
                dis[v]=dis[u]+adjw[u][j];
    cout<<"index: ";
    for(int j=1; j<=n;j++){
        cout<<j<<" ";
    }
    cout<<endl;
    cout<<"dis:  ";
    for(int j=1; j<=n;j++){
        cout<<" "<<dis[j];
    }
    cout<<endl;
    cout<<"par:  ";
    for(int j=1; j<=n;j++){
        cout<<" "<<par[j];
    }
    cout<<endl;

        }

      }

    //cout<<"-----***-----"<<endl;
     }
   }
}
pathPrint(char a[], int des,int source){
       if(par[des]==-1){
        return des;
       }
       pathPrint(a, par[des],source);

       cout<<" "<<a[source]<<"->"<<a[des]<<" cost: "<<dis[des];
}
//a = 1
//b = 2
//c = 3
//d = 4
//e = 5
//f = 6
int main(){
    char a[] = {'0','a','b','c','d','e','f','g','h','i','j','k','l'};
    int u, v, w;
    scanf("%d %d", &n, &e);

    for(int i=0; i<e; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(v);
        adjw[u].push_back(w);
    }


    Ballman(1);

    for(int i = 1; i<=n; i++){
        printf("%c to %c total cost = %d path ",a[2],a[i], dis[i]);
        pathPrint(a, i , 2);
        cout<<endl;
    }
    return 0;
}
