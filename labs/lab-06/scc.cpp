#include <bits/stdc++.h>
#define SIZE 1000106
#define GREY 1
#define WHITE 0
#define BLACK 2
using namespace std;

int n, e;
vector <int> adj[SIZE],adj1[SIZE];

int col[SIZE],arr[SIZE];
int Cycle=0;
int q=0;
void dfs(int u)
{

    col[u]=GREY;
    int v;

    for(int i=0; i<adj[u].size(); i++)
    {

        v=adj[u][i];
        if(col[v]==WHITE)
        {
            dfs(v);
        }
        else if(col[v]==GREY)
        {
            Cycle=1;

        }
    }
    col[u]=BLACK;
    arr[q]=u;
    q++;

}
void dfs_2(int u)
{

    col[u]=GREY;
    int v;
    for(int i=0; i<adj1[u].size(); i++)
    {


        v=adj1[u][i];
        if(col[v]==WHITE)
        {
            dfs_2(v);
        }
        else if(col[v]==GREY)
        {
            Cycle=1;

        }

    }
    col[u]=BLACK;
}

int main()
{
    scanf("%d %d", &n, &e);
    int u, v;
    for(int i=0; i<e; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj1[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        if(col[i]==WHITE)
        {
            dfs(i);
        }
    }
    for(int i=1; i<=n; i++)
    {
        col[i]= WHITE;
    }
    int count=0;
    for(int i=n-1; i>=0; i--)
    {
        if(col[arr[i]] == WHITE)
        {
            count++;
            dfs_2(arr[i]);
        }
    }
    cout<<count<<endl;

    return 0;
}
