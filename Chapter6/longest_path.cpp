#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v,weight;
    Edge(int _v, int _w){ v = _v;weight = _w;}
};

#define MAXN 100001
vector<Edge> Adj[MAXN];
int n,m,d[MAXN];

void DFS(int u, int parent) {
    for (int i=0;i<Adj[u].size();i++) {
        Edge e=Adj[u][i];
        int v=e.v;
        if (v != parent) {
            d[v]=d[u]+e.weight;
            DFS(v,u);
        }
    }
}

int main() {
    cin>>n;
    for (int i=1; i<=n-1; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        Adj[u].push_back(Edge(v, w));
        Adj[v].push_back(Edge(u, w));
    }

    for (int v=1; v<=n;v++) d[v] = 0;
    DFS(1, -1);

    int maxD=-1, index=-1;
    for (int v = 1; v <= n; v++){
        if (d[v] > maxD){
            maxD=d[v];
            index= v;
        }
    }

    for (int v=1;v<=n; v++) d[v]=0;
    DFS(index,-1);

    maxD=-1;
    for (int v=1; v<=n;v++){
        if (d[v]> maxD){
            maxD=d[v];
        }
    }

    cout<<maxD<<endl;
    return 0;
}