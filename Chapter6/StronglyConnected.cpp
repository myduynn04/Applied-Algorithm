#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
vector<int> adj[MAXN];
int num[MAXN],low[MAXN],parent[MAXN];
bool isCutV[MAXN];
vector<pair<int,int>>bridges;
int timeDfs;

void DFS(int u) {
    num[u]=low[u]=++timeDfs;
    int child=0;
    
    for(int v:adj[u]){
     if (num[v] == 0) { 
          child++;
          parent[v]=u;
          DFS(v); 
          low[u] = min(low[u], low[v]);   
          if(parent[u]==-1 && child>1) isCutV[u]=true;       
          if(parent[u]!=-1 && low[v]>=num[u]) isCutV[u]=true;       
          if (low[v]>num[u]) bridges.push_back({min(u,v), max(u,v)});
        } 
     else if (v != parent[u]) low[u] = min(low[u], num[v]);
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    fill(num,num+n+1, 0);
    fill(low,low+n+1,0);
    fill(parent,parent+n+1,-1);
    fill(isCutV,isCutV+n+1,false);  
    timeDfs=0;

    for (int u = 1; u <= n; u++) {
      if (num[u] == 0) DFS(u);
    }

    int cutVertices = 0;
    for(int u=1;u<=n;u++) {
      if(isCutV[u]) cutVertices++;
    }

    cout<<cutVertices<<" "<< bridges.size()<< endl;

    return 0;
}