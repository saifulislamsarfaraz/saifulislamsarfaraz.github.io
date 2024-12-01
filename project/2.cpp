#include <bits/stdc++.h>
using namespace std;
int n,e;
int isBicolorable=1;
vector <long int> adj[1000000];
//int par[SIZE];

int col[1000000];
queue <int> q;
void bfs(int src){
    for(int i=1; i<=n; i++)

    {
        col[i]=0;
    }

    col[src]=100;
   // par[src]=src;
    q.push(src);
    int u, v;
    while(!q.empty())

   {
        u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {


            v=adj[u][i];
            if(col[v]==0)
            {
                if(col[u]==200)
                  {

                      //par[v]=u;
                      col[v]=100;
                      q.push(v);
                  }

                else
                   {


                    //par[v]=u;
                    col[v]=200;
                    q.push(v);
                   }
            }


        }

}
}

int main()

{


    scanf("%d %d", &n, &e);
    int u, v;
    for(int i=0; i<e; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src=1;
   // scanf("%d", &src);
    bfs(src);

    for(int i=1; i<=n; i++)

    {
        if(col[i]==100)
        printf("R\n");
        else
            {
                printf("B\n");

        }
    }


    return 0;
}

