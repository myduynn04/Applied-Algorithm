/*
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
int visited[N]={0};
int num[N]={0};
int low[N]={0};
int tail[N]={0};
int num_cut=0;
int num_bridge =0;
//vi la duyet DFS -> dung ds ke de truy van
map<int, vector<int>> adj;
int timeDFS =0;
void dfs(int u, int pre){
    num[u]=low[u]= ++timeDFS;
    int numchild=0;
    int check =0;
    for (auto v: adj[u]){
        if(v==pre) continue; //neu v la cha truc tiep cua u thi bo qua
        else if(!num[v]){
            //neu v chua duoc tham
            dfs(v, u);
            numchild++;
            low[u]= min(low[u], low[v]);
            if(low[v]==num[v]) num_bridge++;
            if(low[v]>=num[u]) check=1;}
        else{//TH back edge
            low[u]= min(low[u], num[v]);}}
    if(u==pre && numchild>1) num_cut++;
    if(u!=pre && check)num_cut++;
    tail[u]= timeDFS;}
int main(){
    cin >>n>>m;
    for (int i=1; i<=m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a); //do la do thi vo huong
}
    for (int i=1; i<=n; i++){
        if(!num[i]) {dfs(i,i);}}
    cout<<num_cut<<" "<<num_bridge<<endl;}
