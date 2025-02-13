/*
Given an undirected graph containing N vertices and M edges, find all the articulation points and the bridges in the graph.
Input
The first line consists of two space-separated integers denoting N and M,
M lines follow, each containing two space-separated integers X and Y denoting there is an edge between X and Y.
Output
One line consists of two integers denoting the number of articulation points and the number of bridges.
Example
Input
10 12
1 10
10 2
10 3
2 4
4 5
5 2
3 6
6 7
7 3
7 8
8 9
9 7
Output
4  3
*/


#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define M 50005

int n, m;
//vector <int> adj[N]; //truy van den dinh i (adj), duyet cac canh ke cua dinh i (vector adj[i])
map <int, vector<int> > adj;
int timeDFS =0;
//int visited[N]={0};  ta se thay bang viec check num[i]
int num[N]={0};
int low[N]={0};
int tail[N]={0};
int num_bridge=0;
int num_cut=0;


void dfs(int u, int pre){

    low[u] = num[u] = ++timeDFS;


    int numchild=0;
    int check =0;
    //duyet cac con cua u
    for (int v : adj[u]){
        if (v == pre) continue; //neu v la cha truc tiep cua u thi bo qua
        else if(!num[v]){
            dfs(v,u);
            numchild++;
            low[u]= min(low[u], low[v]);
            if(low[v]==num[v]) num_bridge++;
            if(low[v]>=num[u]) check =1;
        }
        else{
            low[u]= min(low[u], num[v]);
        }

    }
    if(pre==u && numchild >1) num_cut++; //truong hop la root
    if (pre !=u && check ) num_cut++;


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
        if (!num[i]) dfs(i,i);
    }
    cout<<num_cut<<" "<<num_bridge<<endl;
}
