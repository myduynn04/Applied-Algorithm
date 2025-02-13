#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 100000

int n, m;
vector <int> adj[N];
int timeDFS =0;
int visited[N]={0};
int num[N]={0};
int low[N]={0};
int tail[N]={0};
int num_bridge=0;

void dfs(int u, int pre){
    low[u] = num[u] = ++timeDFS;
    visited[u]= 1;

    //duyet cac con cua u
    for (int v : adj[u]){
        if (v == pre) continue; //neu v la cha truc tiep cua u thi bo qua
        else if(!visited[v]){
            dfs(v,u);
            low[u]= min(low[u], low[v]);
        }
        else{
            low[u]= min(low[u], num[v]);
        }
        if(low[v]==num[v]) num_bridge++;
    }

    tail[u]= timeDFS;
}


int main(){
    cin >>n>>m;
    for ( int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //duyet cac thanh phan lien thong
    for(int i=1; i<=n; i++){
        if (!visited[i]) dfs(i,i);
    }
    cout<<num_bridge<<endl;
}
